#include  <stdio.h>
#include "Primitives/Primitives.h"
#include "OffFile/OffFile.h"
#include "Transformation/Transformation.h"

int main(void) {
	OffFile* off_file = read_off_file("example.off");

	printf("Vertices: %d\n", off_file->details.vertices);
	printf("Faces: %d\n", off_file->details.faces);
	printf("Edges: %d\n", off_file->details.edges);

	// for (unsigned int i=0; i<off_file->vertices->index; i++) {
		// printf("v%d: ", i);
		// print_vertex((Vertex*)array_list_get(off_file->vertices, i));
	// }
	// printf("\n");
// 
	// for (unsigned int i=0; i<off_file->faces->index; i++) {
		// printf("Face%d: ", i);
		// print_face((Face*)array_list_get(off_file->faces, i));
	// }
	// printf("\n");

	const float TRANSFORM_MATRIX[] = {1, 0, 0, 0, 
									0, 1, 0, 0, 
									0, 0, 1, 0, 
									0, 0, 0, 1};

	printf("Before transformation: ");
	print_vertex((Vertex*)array_list_get(off_file->vertices, 0));
	transformVertex((Vertex*)array_list_get(off_file->vertices, 0), (float*)TRANSFORM_MATRIX, 4);
	printf("After transformation: ");
	print_vertex((Vertex*)array_list_get(off_file->vertices, 0));

	free_off_file(off_file);
	return 0;
}
