#include "Lighting.h"


/**
 * @brief Calculate the intensity of the color based on the normal vector and the light vector
 * @param initial_color The initial color of the face
 * @param normal_vec The normal vector of the face
 * @param light_vec The light vector, assumed to be a unit vecto
 * @return The new color value
*/
ColorValue calc_color_intensity(ColorValue initial_color, Vector normal_vec, Vector light_vec) {
    float m_mag = vec_dot_product(normal_vec, light_vec);
    m_mag = fabs(m_mag);
    return (ColorValue){(uint8_t) (initial_color.greyscale * m_mag)};
}