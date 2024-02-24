#include "Lighting.h"

ColorValue calc_color_intensity(ColorValue initial_color, Vector normal_vec, Vector light_vec) {
    float m_mag = vec_dot_product(normal_vec, light_vec);
    m_mag = fabs(m_mag);
    return (ColorValue){(uint8_t) (initial_color.greyscale * m_mag)};
}