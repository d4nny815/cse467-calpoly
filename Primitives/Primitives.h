#ifndef PRIMITIVES_H
#define PRIMITIVES_H

typedef struct Vertex {
    float x;
    float y;
    float z;
} Vertex;

typedef struct Face {
    Vertex v1;
    Vertex v2;
    Vertex v3;
} Face;

#endif