#ifndef LIGHTING_H
#define LIGHTING_H
#include "../Primitives/Primitives.h"
#include <stdint.h>


ColorValue calc_color_intensity(ColorValue initial_color, Vector light_vec);


#endif