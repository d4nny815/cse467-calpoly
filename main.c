#include  <stdio.h>
#include "OffFile/OffFile.h"

int main(void) {
	OffFile* off_file = read_off_file("example.off");

	printf("Vertices: %d\n", off_file->details.vertices);
	printf("Faces: %d\n", off_file->details.faces);
	printf("Edges: %d\n", off_file->details.edges);

	for (int i=0; i<off_file->vertices->index; i++) {
		Vertex v = *((Vertex*)array_list_get(off_file->vertices, i));
		printf("V%d: (%f, %f, %f) ", i, v.x, v.y, v.z);
	}
	printf("\n");

	free_off_file(off_file);
	return 0;
}
