#ifndef PROJECTION_H
#define PROJECTION_H

#include <stdlib.h>
#include "../Primitives/Primitives.h"

void project_Vx(Vertex* v, uint8_t screen_width);
void project_Vy(Vertex* v, uint8_t screen_height);
void project_Vz(Vertex* v, uint8_t screen_depth);

#endif