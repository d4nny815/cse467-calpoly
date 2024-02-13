#include  <stdio.h>
#include "OffFile/OffFile.h"

int main(void) {
	OffFile* off_file = read_off_file("example.off");

	printf("Vertices: %d\n", off_file->details.vertices);
	printf("Faces: %d\n", off_file->details.faces);
	printf("Edges: %d\n", off_file->details.edges);

	for (int i=0; i<off_file->vertices->index; i++) {
		printf("v%d: ", i);
		print_vertex((Vertex*)array_list_get(off_file->vertices, i));
	}
	printf("\n");

	for (int i=0; i<off_file->faces->index; i++) {
		printf("Face%d: ", i);
		print_face((Face*)array_list_get(off_file->faces, i));
	}
	printf("\n");


	free_off_file(off_file);
	return 0;
}
