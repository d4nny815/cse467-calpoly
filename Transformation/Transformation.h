#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "../Primitives/Primitives.h"
#include <stdlib.h>
#include <stdio.h>

void transformVertex(Vertex* v, float* transform_matrix, const int num_dimensions);
void transformFace(Face* f, float* transform_matrix, const int num_dimensions);

#endif