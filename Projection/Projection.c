#include "Projection.h"

// TODO: test these

void project_Vx(Vertex* v, uint8_t screen_width) {
    int8_t shift = (int8_t)v->x >> 2;
    shift += 1;
    shift >>= 1;
    shift *= screen_width;
    v->x = shift;
    return;
}
void project_Vy(Vertex* v, uint8_t screen_height) {
    int8_t shift = -(int8_t)v->y >> 2;
    shift += 1;
    shift >>= 1;
    shift *= screen_height;
    v->y = shift;
    return;
}

void project_Vz(Vertex* v, uint8_t screen_depth) {
    int8_t shift = (int8_t)v->z >> 2;
    shift += 1;
    shift >>= 1;
    shift *= screen_depth;
    v->z = shift;
    return;
}

