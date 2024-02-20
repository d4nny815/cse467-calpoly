#include "Rasterization.h"
#include <stdio.h>
#include <assert.h>


void test_geeksforgeeks() {
    Vertex v1 = {-1, 1, 1};
    Vertex v2 = {5, 3, -1};

    ArrayList* vertices = getLineVertices(v1, v2);
    for (unsigned int i = 0; i < vertices->index; i++) {
        Vertex* v = (Vertex*) array_list_get(vertices, i);
        printf("Vertex %d: (%f, %f, %f)\n", i, v->x, v->y, v->z);
    }

    array_list_free(vertices, free_vertex);
}

void test_compareVertices1() {
    Vertex v1 = {1, 2, 3};
    Vertex v2 = {1, 2, 3};

    assert(compareVertices(v1, v2) == 1);
    printf("test_compareVertices1 passed\n");
}

void test_compareVertices2() {
    Vertex v1 = {1, 2, 3};
    Vertex v2 = {1, 2, 4};

    assert(compareVertices(v1, v2) == 0);
    printf("test_compareVertices2 passed\n");
}

void test_hashVertex() {
    ArrayList* vertices = array_list_new();
    uint64_t count = 0;

    for (float i = 0; i < HEIGHT; i+=.5) {
        for (float j = 0; j < WIDTH; j+=.5) {
            for (float k = 0; k < DEPTH; k+=.5) {
                Vertex* v = (Vertex*) malloc(sizeof(Vertex));
                v->x = i;
                v->y = j;
                v->z = k;
                array_list_append(vertices, v);
                count++;
            }
        }
    }

    assert(vertices->index == count);
    printf("test_hashVertex passed\n");
}

// void test_hashVertex2() {
//     Vertex v = {1.0, 1.5 , 2.0};
// }



int main(void) {
    test_geeksforgeeks();
    test_compareVertices1();
    test_compareVertices2();
    test_hashVertex();


    return 0;
}