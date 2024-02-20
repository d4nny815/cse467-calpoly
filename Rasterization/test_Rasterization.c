#include "Rasterization.h"

int main(void) {
    Vertex v1 = {-1, 1, 1};
    Vertex v2 = {5, 3, -1};

    ArrayList* vertices = getLineVertices(&v1, &v2);
    for (unsigned int i = 0; i < vertices->index; i++) {
        Vertex* v = (Vertex*) array_list_get(vertices, i);
        printf("Vertex %d: (%f, %f, %f)\n", i, v->x, v->y, v->z);
    }

    array_list_free(vertices, free_vertex);
    return 0;
}