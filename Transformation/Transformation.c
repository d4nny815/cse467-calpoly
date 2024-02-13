#include "Transformation.h"


void transformVertex(Vertex* v, float* transform_matrix, int col) {
    float vertex_vector[] = {v->x, v->y, v->z, 0};
    float* result_mat = (float*) malloc(sizeof(float) * col);

    for (int i=0; i<col; i++) {
        result_mat[i] = 0; 
        for (int j=0; j<col; j++) {
            result_mat[i] += vertex_vector[j] * transform_matrix[j*col + i];
        }
    }
    v->x = result_mat[0];
    v->y = result_mat[1];
    v->z = result_mat[2];
    free(result_mat);
    return;
}
