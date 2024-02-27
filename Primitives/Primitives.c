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
 * @brief calculates the unit normal vector of a face
 * @param v1 The first vertex of the face.
 * @param v2 The second vertex of the face.
 * @param v3 The third vertex of the face.
 * @return The unit normal vector of the face.
*/
Vector calculate_unit_normal_vec(Vertex v1, Vertex v2, Vertex v3) {
    Vector normal = calculate_normal_vec(v1, v2, v3);
    float dot = vec_dot_product(normal, normal);
    float inv_sqrt = q_rsqrt(dot);
    return vec_scalar(normal, inv_sqrt);
}



/**
 * @brief Calculates the cross product of two vectors.
 * @param A The first vector.
 * @param B The second vector.
 * @return The cross product of the two vectors.
 * @note https://www.symbolab.com/solver/vector-cross-product-calculator 
*/
Vector vec_cross_product(Vector A, Vector B) {
    Vector C;
    C.i = A.j * B.k - A.k * B.j;
    C.j = A.k * B.i - A.i * B.k;
    C.k = A.i * B.j - A.j * B.i;
    return C;
}


/**
 * @brief Calculates the dot product of two vectors.
 * @param A The first vector.
 * @param B The second vector.
 * @return The dot product of the two vectors.
 * @note https://www.calculatorsoup.com/calculators/algebra/dot-product-calculator.php 
*/
float vec_dot_product(Vector A, Vector B) {
    return A.i * B.i + A.j * B.j + A.k * B.k;
}


/**
 * @brief Multiplies a vector by a scalar.
 * @param A The vector to multiply.
 * @param scalar The scalar to multiply by.
 * @return The resulting vector.
*/
Vector vec_scalar(Vector A, float scalar) {
    return (Vector) {A.i * scalar, A.j * scalar, A.k * scalar};
}


/**
 * @brief Calculates the magnitude of a vector.
 * @param A The vector to calculate the magnitude of.
 * @return The magnitude of the vector.
*/
float vec_magnitude(Vector A) {
    float mag = sqrt(A.i * A.i + A.j * A.j + A.k * A.k);
    return mag;
}


/**
 * @brief Normalizes a vector.
 * @param A The vector to normalize.
 * @return The normalized vector.
 * @note https://www.symbolab.com/solver/vector-normalize-calculator
*/
Vector vec_normalize(Vector A) {
    float dot = vec_dot_product(A, A);
    float inv_sqrt = q_rsqrt(dot);
    return vec_scalar(A, inv_sqrt);
}


/**
 * @brief Calculates the inverse square root of a number.
 * @param number The number to calculate the inverse square root of.
 * @return The inverse square root of the number.
 * @note https://en.wikipedia.org/wiki/Fast_inverse_square_root
*/
float q_rsqrt(float number) {
    union {
      float    f;
      uint32_t i;
    } conv = { .f = number };
    conv.i  = 0x5f3759df - (conv.i >> 1);
    conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
    return conv.f;
}


/**
 * @brief Prints the vertex to the console.
 * @param v The vertex to print.
*/
void print_vertex(Vertex v) {
    printf("(%f, %f, %f)", v.x, v.y, v.z);
}


/**
 * @brief Prints the vertex to the console.
 * @param v The vertex to print.
*/
void print_vertex_i(Vertex_i v) {
    printf("(%hhu, %hhu, %hhu)", v.x, v.y, v.z);
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
    printf("%X", c.greyscale);
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
 * @brief Prints the face to the console.
 * @param f The face to print.
*/
void print_face_i(Face_i f) {
    printf("Face: {\n");
    printf("\tv1: ");
    print_vertex_i(f.v1);
    printf("\n\tv2: ");
    print_vertex_i(f.v2);
    printf("\n\tv3: ");
    print_vertex_i(f.v3);
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