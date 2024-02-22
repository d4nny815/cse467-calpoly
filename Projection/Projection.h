#ifndef PROJECTION_H
#define PROJECTION_H

#include <stdlib.h>
#include "../Primitives/Primitives.h"

uint8_t project_Vx(Vertex v, uint8_t screen_width);
uint8_t project_Vy(Vertex v, uint8_t screen_height);
uint8_t project_Vz(Vertex v, uint8_t screen_depth);
Face_i* project_Face(Face f, uint8_t screen_width, uint8_t screen_height, uint8_t screen_depth);

#endif