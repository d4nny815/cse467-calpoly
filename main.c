#include  <stdio.h>
#include "Primitives/Primitives.h"
#include "OffFile/OffFile.h"
#include "Transformation/Transformation.h"
#include "Lighting/Lighting.h"
#include "Projection/Projection.h"
#include "Rasterization/Rasterization.h"
#include "PGMFile/PGMFile.h"

int main(void) {
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
	float TRANSFORM_MATRIX[] = {1, 0, 0, 0, 
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
	Vector LIGHT_VEC = {1, 1, 1};
	for (unsigned int i=0; i<faces->index; i++) {
		Face* face = (Face*) array_list_get(faces, i);
		face->color = calc_color_intensity(face->color, face->normal, LIGHT_VEC);
	}
	

	// Projection
	// Convert from 3D to 2D
		printf("\nProjection Stage\n");
	const uint8_t SCREEN_WIDTH = WIDTH - 1;
	const uint8_t SCREEN_HEIGHT = HEIGHT - 1;
	const uint8_t SCREEN_DEPTH = DEPTH - 1;
	ArrayList* projected_faces = array_list_new(); // this should overwrite the old faces
	for (unsigned int i=0; i<faces->index; i++) {
		Face* face = (Face*) array_list_get(faces, i);
		Face_i* projected_face = project_Face(*face, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH);
		array_list_append(projected_faces, projected_face);
	}


	// Rasterization
	printf("\nRasterization Stage\n");
	uint8_t** Z_BUFFER = (uint8_t**) malloc(HEIGHT * sizeof(uint8_t*));
	uint8_t** COLOR_BUFFER = (uint8_t**) malloc(HEIGHT * sizeof(uint8_t*));

	for (unsigned int i=0; i<HEIGHT; i++) {
		Z_BUFFER[i] = (uint8_t*) malloc(WIDTH * sizeof(uint8_t));
		COLOR_BUFFER[i] = (uint8_t*) malloc(WIDTH * sizeof(uint8_t));
		for (unsigned int j=0; j<WIDTH; j++) {
			Z_BUFFER[i][j] = DEPTH - 1;
			COLOR_BUFFER[i][j] = 0;
		}
	}


	rasterize(projected_faces, Z_BUFFER, COLOR_BUFFER);

	// Make PGM file
	makePGMFile(WIDTH, HEIGHT, DEPTH - 1, COLOR_BUFFER, "teapot.pgm");
	// Freeing memory
	for (unsigned int i=0; i<WIDTH; i++) {
		free(Z_BUFFER[i]);
		free(COLOR_BUFFER[i]);
	}
	free(Z_BUFFER);
	free(COLOR_BUFFER);

	array_list_free(faces, free_face);
	array_list_free(projected_faces, free_face);

	return 0;
}
