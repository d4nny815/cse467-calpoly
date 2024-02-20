#include "Rasterization.h"


/**
 * @brief Get the Vertices of a line between two vertices.
 * @param v1 The first vertex.
 * @param v2 The second vertex.
 * @return The vertices of the line.
 * @note https://www.geeksforgeeks.org/bresenhams-algorithm-for-3-d-line-drawing/
*/
ArrayList* getLineVertices(Vertex* v1, Vertex* v2) {
    ArrayList* vertices = array_list_new();

    Vertex* v = (Vertex*) malloc(sizeof(Vertex));
    v->x = v1->x;
    v->y = v1->y;
    v->z = v1->z;
    array_list_append(vertices, v);

    int x1 = v1->x;
    int y1 = v1->y;
    int z1 = v1->z;
    int x2 = v2->x;
    int y2 = v2->y;
    int z2 = v2->z;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int dz = abs(z2 - z1);

    int xs = (x2 - x1) > 0 ? 1 : -1;
    int ys = (y2 - y1) > 0 ? 1 : -1;
    int zs = (z2 - z1) > 0 ? 1 : -1;

    // Driving axis is X-axis"
    if (dx >= dy && dx >= dz) {
        int p1 = 2 * dy - dx;
        int p2 = 2 * dz - dx;
        while (x1 != x2) {
            x1 += xs;
            if (p1 >= 0) {
              y1 += ys;
              p1 -= 2 * dx;
            }
            if (p2 >= 0) {
              z1 += zs;
              p2 -= 2 * dx;
            }
            p1 += 2 * dy;
            p2 += 2 * dz;
            Vertex* v = (Vertex*) malloc(sizeof(Vertex));
            v->x = x1;
            v->y = y1;
            v->z = z1;

            array_list_append(vertices, v);
        }
    } 
 
    // Driving axis is Y-axis"
    else if (dy >= dx && dy >= dz) {
        int p1 = 2 * dx - dy;
        int p2 = 2 * dz - dy;
        while (y1 != y2) {
            y1 += ys;
            if (p1 >= 0) {
              x1 += xs;
              p1 -= 2 * dy;
            }
            if (p2 >= 0) {
              z1 += zs;
              p2 -= 2 * dy;
            }
            p1 += 2 * dx;
            p2 += 2 * dz;
            Vertex* v = (Vertex*) malloc(sizeof(Vertex));
            v->x = x1;
            v->y = y1;
            v->z = z1;

            array_list_append(vertices, v);
        }
    } 
    
    // Driving axis is Z-axis"
    else {
        int p1 = 2 * dy - dz;
        int p2 = 2 * dx - dz;
        while (z1 != z2) {
            z1 += zs;
            if (p1 >= 0) {
              y1 += ys;
              p1 -= 2 * dz;
            }
            if (p2 >= 0) {
              x1 += xs;
              p2 -= 2 * dz;
            }
            p1 += 2 * dy;
            p2 += 2 * dx;
            Vertex* v = (Vertex*) malloc(sizeof(Vertex));
            v->x = x1;
            v->y = y1;
            v->z = z1;

            array_list_append(vertices, v);
        }
    }
    return vertices;
}


// /**
//  * @brief Get the Vertices of a face.
//  * @param f The face.
//  * @return The vertices of the face.
// */
// Vertex* getVerticesInFace(Face* f) {

// }


// /**
//  * @brief Rasterize the faces.
//  * @param faces The faces to rasterize.
//  * @return The frame buffer of the screen.
//  * @note image to be displayed on the screen of WIDTH x HEIGHT.
// */
// uint8_t** rasterize(ArrayList* faces) {

// }
