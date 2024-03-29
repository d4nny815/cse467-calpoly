#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define DEFAULT_COLOR (ColorValue) {255}

typedef struct Vertex {
    float x;
    float y;
    float z;
} Vertex;

typedef struct Vertex_i {
    uint8_t x;
    uint8_t y;
    uint8_t z;
} Vertex_i;


typedef struct Vector {
    float i;
    float j;
    float k;
} Vector;

// typedef struct ColorValue {
//     uint8_t r;
//     uint8_t g;
//     uint8_t b;
// } ColorValue;

typedef struct ColorValue {
    uint8_t greyscale;
} ColorValue;

typedef struct Face {
    Vertex v1;
    Vertex v2;
    Vertex v3;
    Vector normal;
    ColorValue color;
} Face;

typedef struct Face_i {
    Vertex_i v1;
    Vertex_i v2;
    Vertex_i v3;
    Vector normal;
    ColorValue color;
} Face_i;


Vector calculate_normal_vec(Vertex v1, Vertex v2, Vertex v3);
Vector calculate_unit_normal_vec(Vertex v1, Vertex v2, Vertex v3);
Vector vec_cross_product(Vector A, Vector B);
float vec_dot_product(Vector A, Vector B);
Vector vec_scalar(Vector A, float scalar);
float q_rsqrt(float number);
float vec_magnitude(Vector A);
Vector vec_normalize(Vector A);

void print_vertex(Vertex v);
void print_vertex_i(Vertex_i v);
void print_face(Face f);
void print_face_i(Face_i f);
void print_vector(Vector v);
void print_color(ColorValue c);

void* free_vertex(void* vertex);
void* free_face(void* face);




#endif