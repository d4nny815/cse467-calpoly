#include "Primitives.h"


/**
 * @brief calculates the normal vector of a face
 * @param v1 The first vertex of the face.
 * @param v2 The second vertex of the face.
 * @param v3 The third vertex of the face.
 * @return The normal vector of the face.
*/
Vector calculate_normal_vec(Vertex v1, Vertex v2, Vertex v3) {
    Vector vec_v1_v2 = (Vector) {v2.x - v1.x, v2.y - v1.y, v2.z - v1.z};
    Vector vec_v1_v3 = (Vector) {v3.x - v1.x, v3.y - v1.y, v3.z - v1.z};
    return vec_cross_product(vec_v1_v2, vec_v1_v3);
}


/**
 * @brief Calculates the cross product of two vectors.
 * @param A The first vector.
 * @param B The second vector.
 * @return The cross product of the two vectors.
*/
Vector vec_cross_product(Vector A, Vector B) {
    Vector C;
    C.i = A.j * B.k - A.k * B.j;
    C.j = A.k * B.i - A.i * B.k;
    C.k = A.i * B.j - A.j * B.i;
    return C;
}


/**
 * @brief Prints the vertex to the console.
 * @param v The vertex to print.
*/
void print_vertex(Vertex v) {
    printf("(%f, %f, %f)", v.x, v.y, v.z);
}



/**
 * @brief Prints the vector to the console.
 * @param v The vector to print.
*/
void print_vector(Vector v) {
    printf("<%f, %f, %f>", v.i, v.j, v.k);
}


/**
 * @brief Prints the color to the console.
 * @param c The color to print.
*/
void print_color(ColorValue c) {
    printf("(%d, %d, %d)", c.r, c.g, c.b);
}


/**
 * @brief Prints the face to the console.
 * @param f The face to print.
*/
void print_face(Face f) {
    printf("Face: {\n");
    printf("\tv1: ");
    print_vertex(f.v1);
    printf("\n\tv2: ");
    print_vertex(f.v2);
    printf("\n\tv3: ");
    print_vertex(f.v3);
    printf("\n\tnormal: ");
    print_vector(f.normal);
    printf("\n\tcolor: ");
    print_color(f.color);
    printf("\n}\n");
}


/**
 * @brief function pointer to free a vertex
 * @param vertex The vertex to free.
*/
void* free_vertex(void* vertex) {
    free(vertex);
    return NULL;
}


/**
 * @brief function pointer to free a face
 * @param face The face to free.
*/
void* free_face(void* face) {
    free(face);
    return NULL;
}