#include "Projection.h"

// TODO: test these
// TODO: make sure these convert float to int coords, will make rasteration easier

// Project objects on the screen space
uint8_t project_Vx(Vertex v, uint8_t screen_width) {
    // for testing purposes, to see accuracy compared to int math
    // double x = (((double)v->x / 4.0) + 1) / 2.0;
    // x *= screen_width + 1;
    // v->x = x;
    // printf("x using float math %f with v->x: %f\n", x, v->x);

    int16_t shift = (int16_t)(v.x * 128);  // 2^8, so we can use bit shift and not lose precision
    shift = ((shift >> 2) + 128) >> 1;
    shift *= screen_width;
    shift >>= 7;
    // printf("x using int math %hhu with v->x: %f\n", (uint8_t)shift, v->x);
    return (uint8_t)shift;
}
uint8_t project_Vy(Vertex v, uint8_t screen_height) {
    int16_t shift = (int16_t)(-v.y * 128);  // 2^8, so we can use bit shift and not lose precision
    shift = ((shift >> 2) + 128) >> 1;
    shift *= screen_height;
    shift >>= 7;
    return (uint8_t)shift;
}

uint8_t project_Vz(Vertex v, uint8_t screen_depth) {

    int16_t shift = (int16_t)(v.z * 128);  // 2^8, so we can use bit shift and not lose precision
    shift = ((shift >> 2) + 128) >> 1;
    shift *= screen_depth;
    shift >>= 7;
    return (uint8_t)shift;
}

Face_i* project_Face(Face f, uint8_t screen_width, uint8_t screen_height, uint8_t screen_depth) {
    Face_i* new_f = (Face_i*) malloc(sizeof(Face_i));
    if (new_f == NULL) { return NULL; }

    new_f->v1.x = project_Vx(f.v1, screen_width);
    new_f->v1.y = project_Vy(f.v1, screen_height);
    new_f->v1.z = project_Vz(f.v1, screen_depth);

    new_f->v2.x = project_Vx(f.v2, screen_width);
    new_f->v2.y = project_Vy(f.v2, screen_height);
    new_f->v2.z = project_Vz(f.v2, screen_depth);

    new_f->v3.x = project_Vx(f.v3, screen_width);
    new_f->v3.y = project_Vy(f.v3, screen_height);
    new_f->v3.z = project_Vz(f.v3, screen_depth);

    new_f->normal = f.normal;
    new_f->color = f.color;
    return new_f;
}

