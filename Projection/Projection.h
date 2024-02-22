#ifndef PROJECTION_H
#define PROJECTION_H

#define FLOAT_SCALAR 128.0
#define SHIFT 7 
#define SPACE_CONST 2
#define SPACE_TRANSLATOR (unsigned int)(SPACE_CONST*FLOAT_SCALAR)

#include <stdlib.h>
#include "../Primitives/Primitives.h"

uint8_t project_Vx(Vertex v, uint8_t screen_width);
uint8_t project_Vy(Vertex v, uint8_t screen_height);
uint8_t project_Vz(Vertex v, uint8_t screen_depth);
Face_i* project_Face(Face f, uint8_t screen_width, uint8_t screen_height, uint8_t screen_depth);

#endif