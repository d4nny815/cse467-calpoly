#ifndef RASTERIZATION_H
#define RASTERIZATION_H

// Where DISPLAY_WIDTH and DISPLAY_HEIGHT are the dimensions of the display
#define DISPLAY_WIDTH 256
#define DISPLAY_HEIGHT 256
#define DEPTH 256

#include <unistd.h>
#include <stdint.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

// ? what if i calc the max amount of blocks a polygon can be and that becomes the MAX POLYGON Buffer size 
#define MAX_POLYGON_BUFFER DISPLAY_WIDTH*DISPLAY_HEIGHT*DEPTH // need a 2^24 = 16MB Memory Block if storing 8b color
// ! this changes depending on display size
#define FRAME_BUFFER_SIZE DISPLAY_HEIGHT*DISPLAY_WIDTH  // need a 2^16 = 64kB Framebuffer 

#include "../Primitives/Primitives.h"
#include "../ArrayList/ArrayList.h"
#include <stdlib.h>
#include <math.h>

ArrayList* getLineVertices(Vertex_i v1, Vertex_i v2);
int compareVertices(const Vertex_i v1, const Vertex_i v2);
uint32_t hashVertex(const Vertex_i v);
ArrayList* getVerticesInFace(Face_i f);
void rasterize(ArrayList* faces, uint8_t* Z_BUFFER, uint8_t* COLOR_BUFFER);
void parallel_rasterize(ArrayList* faces, uint8_t* Z_BUFFER, uint8_t* COLOR_BUFFER, int num_processes);




#endif