#ifndef RASTERIZATION_H
#define RASTERIZATION_H
#define WIDTH 256
#define HEIGHT 256
#define DEPTH 256
#define MAX_POLYGON_BUFFER WIDTH*HEIGHT*DEPTH
#define FRAME_BUFFER_SIZE HEIGHT*WIDTH

#include "../Primitives/Primitives.h"
#include "../ArrayList/ArrayList.h"
#include <stdlib.h>
#include <math.h>

ArrayList* getLineVertices(Vertex_i v1, Vertex_i v2);
int compareVertices(const Vertex_i v1, const Vertex_i v2);
uint32_t hashVertex(const Vertex_i v);
ArrayList* getVerticesInFace(Face_i f);
void rasterize(ArrayList* faces, uint8_t** Z_BUFFER, uint8_t** COLOR_BUFFER);




#endif