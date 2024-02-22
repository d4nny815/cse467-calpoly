#include  <stdio.h>
#include "Primitives/Primitives.h"
#include "OffFile/OffFile.h"
#include "Transformation/Transformation.h"
#include "Lighting/Lighting.h"
#include "Projection/Projection.h"
#include "Rasterization/Rasterization.h"

// #define TRANSFORM_MATRIX (float*) {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}

int main(void) {
	// reading OFF file
	printf("Reading OffFile\n");
	// OffFile* off_file = read_off_file("teapot.off");
	OffFile* off_file = read_off_file("example.off");
	for (unsigned int i=0; i<off_file->faces->index; i++) {
		Face* face = (Face*) array_list_get(off_file->faces, i);
		print_face(*face);
	}

	// Transformation
	printf("\nTransformation stage\n");
	float TRANSFORM_MATRIX[] = {1, 0, 0, 0, 
								0, 1, 0, 0, 
								0, 0, 1, 0, 
								0, 0, 0, 1};
	const int MATRIX_DIM = 4;

	for (unsigned int i=0; i<off_file->faces->index; i++) {
		Face* face = (Face*) array_list_get(off_file->faces, i);
		transformFace(face, TRANSFORM_MATRIX, MATRIX_DIM);

		print_face(*face);
	}


	// Lighting
	printf("\nLighting Stage\n");
	Vector LIGHT_VEC = {1, 1, 1};
	for (unsigned int i=0; i<off_file->faces->index; i++) {
		Face* face = (Face*) array_list_get(off_file->faces, i);
		face->color.greyscale = calc_color_intensity(face->color, face->normal, LIGHT_VEC);

		print_face(*face);
	}
	

	// Projection
	// Convert from 3D to 2D
	// Convert float coords to uint8_t
	printf("\nProjection Stage\n");
	const uint8_t SCREEN_WIDTH = 255;
	const uint8_t SCREEN_HEIGHT = 255;
	const uint8_t SCREEN_DEPTH = 255;
	ArrayList* projected_faces = array_list_new();
	for (unsigned int i=0; i<off_file->faces->index; i++) {
		Face* face = (Face*) array_list_get(off_file->faces, i);
		Face_i* projected_face = project_Face(*face, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH);
		array_list_append(projected_faces, (void*)projected_face);
		print_face_i(*projected_face);
	}


	// Rasterization
	printf("\nRasterization Stage\n");
	for (unsigned int i=0; i<projected_faces->index; i++) {
		Face_i* face = (Face_i*) array_list_get(projected_faces, i);


		print_face_i(*face);
	}


	array_list_free(projected_faces, free_face);
	free_off_file(off_file);
	return 0;
}
