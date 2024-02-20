#ifndef RASTERIZATION_H
#define RASTERIZATION_H
#define WIDTH 256
#define HEIGHT 256
#define DEPTH 256
#define MAX_POLYGON_BUFFER WIDTH+HEIGHT+DEPTH

#include "../Primitives/Primitives.h"
#include "../ArrayList/ArrayList.h"
#include <stdlib.h>
#include <math.h>


ArrayList* getLineVertices(Vertex* v1, Vertex* v2);
// Vertex* getVerticesInFace(Face* f);
// uint8_t** rasterize(ArrayList* faces);


#endif