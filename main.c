#include  <stdio.h>
#include "Primitives/Primitives.h"
#include "OffFile/OffFile.h"
#include "Transformation/Transformation.h"
#include "Lighting/Lighting.h"
#include "Projection/Projection.h"
#include "Rasterization/Rasterization.h"
#include "PGMFile/PGMFile.h"

#include <stdlib.h>

// float generate_random_float() {
// 	float range = 1.6f - 0.8f;
// 	float num = (float)rand() / RAND_MAX;
// 	return (num * range) + 0.8f;
// }

int main(int argc, char** argv) {
	// reading OFF file
	// * This stage would be done by the CPU
	printf("Reading OffFile\n");
	OffFile* off_file = read_off_file("teapot.off");
	// OffFile* off_file = read_off_file("example.off");
	ArrayList* faces = array_list_new(); // copy everything over

	for (unsigned int i=0; i<off_file->faces->index; i++) {
		Face* face = (Face*) array_list_get(off_file->faces, i);
		Face* f = (Face*) malloc(sizeof(Face));
		f->v1 = face->v1;
		f->v2 = face->v2;
		f->v3 = face->v3;
		f->normal = face->normal;
		f->color = face->color;
		array_list_append(faces, f);
	}
	free_off_file(off_file);

	// * From here on, the stages would be done by the GPU	
	// Transformation
	printf("\nTransformation stage\n");
	float TRANSFORM_MATRIX[] = {-1, 0, 0, 0, 
								0, 1, 0, 0, 
								0, 0, 1, 0, 
								0, 0, 0, 1};
	const int MATRIX_DIM = 4;

	for (unsigned int i=0; i<faces->index; i++) {
		Face* face = (Face*) array_list_get(faces, i);
		transformFace(face, TRANSFORM_MATRIX, MATRIX_DIM);
	}


	// Lighting
	printf("\nLighting Stage\n");
	Vector LIGHT_VEC = {.6, .707, .9};
	Vector LIGHT_VEC_NORMALIZED = vec_normalize(LIGHT_VEC);
	for (unsigned int i=0; i<faces->index; i++) {
		Face* face = (Face*) array_list_get(faces, i);
		face->color = calc_color_intensity(face->color, face->normal, LIGHT_VEC_NORMALIZED);
	}
	

	// Projection
	// Convert from 3D to 2D
	printf("\nProjection Stage\n");
	const uint8_t SCREEN_WIDTH = DISPLAY_WIDTH - 1;
	const uint8_t SCREEN_HEIGHT = DISPLAY_HEIGHT - 1;
	const uint8_t SCREEN_DEPTH = DEPTH - 1;
	ArrayList* projected_faces = array_list_new(); // this should overwrite the old faces
	for (unsigned int i=0; i<faces->index; i++) {
		Face* face = (Face*) array_list_get(faces, i);
		Face_i* projected_face = project_Face(*face, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH);
		array_list_append(projected_faces, projected_face);
	}


	// Rasterization
	printf("\nRasterization Stage\n");

	uint8_t* Z_BUFFER = (uint8_t*) malloc(FRAME_BUFFER_SIZE * sizeof(uint8_t));
	uint8_t* COLOR_BUFFER = (uint8_t*) malloc(FRAME_BUFFER_SIZE * sizeof(uint8_t));
	memset(Z_BUFFER, DEPTH - 1, FRAME_BUFFER_SIZE * sizeof(uint8_t));
	memset(COLOR_BUFFER, 0, FRAME_BUFFER_SIZE * sizeof(uint8_t));
	
	int NUM_PROCESSES;
	if (argc == 1) {
		NUM_PROCESSES = 1;
	} else {
		NUM_PROCESSES = atoi(argv[1]);
	}
	parallel_rasterize(projected_faces, Z_BUFFER, COLOR_BUFFER, NUM_PROCESSES);

	// Make PGM file
	printf("\nMaking PGM file\n");
	makePGMFile(DISPLAY_WIDTH, DISPLAY_HEIGHT, DEPTH - 1, COLOR_BUFFER, "teapot.pgm");

	free(Z_BUFFER);
	free(COLOR_BUFFER);

	array_list_free(projected_faces, free_face);
	array_list_free(faces, free_face);

	return 0;
}
