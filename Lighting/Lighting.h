#ifndef LIGHTING_H
#define LIGHTING_H
#include "../Primitives/Primitives.h"
#include <stdint.h>
#include <math.h>


ColorValue calc_color_intensity(ColorValue initial_color, Vector normal_vec, Vector light_vec);


#endif