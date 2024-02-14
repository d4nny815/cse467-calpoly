// Test file for Primitives.c
// Copilot generated code

#include <stdio.h>
#include <assert.h>
#include "Primitives.h"
#define EPSILON 0.1

void test_calculate_normal_vec() {
    Vertex v1 = {0, 0, 0};
    Vertex v2 = {1, 0, 0};
    Vertex v3 = {0, 1, 0};
    Vector normal = calculate_normal_vec(v1, v2, v3);
    Vector expected = {0, 0, 1};
    assert(normal.i - expected.i < EPSILON && normal.j - expected.j < EPSILON && normal.k - expected.k < EPSILON);
}

void test_calculate_unit_normal_vec() {
    Vertex v1 = {0, 0, 0};
    Vertex v2 = {1, 0, 0};
    Vertex v3 = {0, 1, 0};
    Vector unit_normal = calculate_unit_normal_vec(v1, v2, v3);
    Vector expected = {0, 0, 1};
    assert(unit_normal.i - expected.i < EPSILON && unit_normal.j - expected.j < EPSILON && unit_normal.k - expected.k < EPSILON);
}

void test_vec_cross_product() {
    Vector A = {1, 0, 0};
    Vector B = {0, 1, 0};
    Vector cross_product = vec_cross_product(A, B);
    assert(cross_product.i == 0 && cross_product.j == 0 && cross_product.k == 1);
}

void test_vec_dot_product() {
    Vector A = {1, 2, 3};
    Vector B = {4, 5, 6};
    float dot_product = vec_dot_product(A, B);
    assert(dot_product == 32);
}

void test_vec_scalar() {
    Vector A = {1, 2, 3};
    float scalar = 2;
    Vector result = vec_scalar(A, scalar);
    assert(result.i == 2 && result.j == 4 && result.k == 6);
}

void test_vec_magnitude() {
    Vector A = {3, 4, 0};
    float magnitude = vec_magnitude(A);
    assert(magnitude == 25);
}

void test_q_rsqrt() {
    float number = 16;
    float result = q_rsqrt(number);
    float expected = 0.25;
    assert(result - expected < EPSILON && expected - result < EPSILON);
}

void test_print_vertex() {
    Vertex v = {1, 2, 3};
    printf("Printing vertex: ");
    print_vertex(v);
    printf("\n");
}

void test_print_vector() {
    Vector v = {1, 2, 3};
    printf("Printing vector: ");
    print_vector(v);
    printf("\n");
}

void test_print_color() {
    ColorValue c = {255, 0, 0};
    printf("Printing color: ");
    print_color(c);
    printf("\n");
}

void test_print_face() {
    Face f = {
        .v1 = {0, 0, 0},
        .v2 = {1, 0, 0},
        .v3 = {0, 1, 0},
        .normal = {0, 0, 1},
        .color = {255, 0, 0}
    };
    printf("Printing face:\n");
    print_face(f);
}

int main() {
    test_calculate_normal_vec();
    test_calculate_unit_normal_vec();
    test_vec_cross_product();
    test_vec_dot_product();
    test_vec_scalar();
    test_vec_magnitude();
    test_q_rsqrt();
    test_print_vertex();
    test_print_vector();
    test_print_color();
    test_print_face();

    printf("All tests passed!\n");

    return 0;
}