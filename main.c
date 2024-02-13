#include  <stdio.h>
#include "Primitives/Primitives.h"
#include "OffFile/OffFile.h"
#include "Transformation/Transformation.h"

int main(void) {
	OffFile* off_file = read_off_file("example.off");

	const float TRANSFORM_MATRIX[] = {1, 0, 0, 0, 
									0, 1, 0, 0, 
									0, 0, 1, 0, 
									0, 0, 0, 1};

	Vertex* v = (Vertex*) array_list_get(off_file->vertices, 0);
	transformVertex(v, (float*) TRANSFORM_MATRIX, 4);

	free_off_file(off_file);
	return 0;
}
