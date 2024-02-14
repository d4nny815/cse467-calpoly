#include  <stdio.h>
#include "Primitives/Primitives.h"
#include "OffFile/OffFile.h"
#include "Transformation/Transformation.h"

#define TRANSFORM_MATRIX (float*) {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}

int main(void) {
	OffFile* off_file = read_off_file("teapot.off");
	// OffFile* off_file = read_off_file("example.off");

	for (unsigned int i=0; i<off_file->faces->index; i++) {
		Face* face = (Face*) array_list_get(off_file->faces, i);
		print_face(*face);
	}

	free_off_file(off_file);
	return 0;
}
