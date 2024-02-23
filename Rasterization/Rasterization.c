#include "Rasterization.h"


/**
 * @brief Get the Vertices of a line between two vertices.
 * @param v1 The first vertex.
 * @param v2 The second vertex.
 * @return The vertices of the line.
 * @note https://www.geeksforgeeks.org/bresenhams-algorithm-for-3-d-line-drawing/
*/
ArrayList* getLineVertices(Vertex_i v1, Vertex_i v2) {
    ArrayList* vertices = array_list_new();

    // make a copy of the first vertex
    Vertex_i* v = (Vertex_i*) malloc(sizeof(Vertex_i));
    v->x = v1.x;
    v->y = v1.y;
    v->z = v1.z;
    array_list_append(vertices, v);

    uint8_t x1 = v1.x;
    uint8_t y1 = v1.y;
    uint8_t z1 = v1.z;
    uint8_t x2 = v2.x;
    uint8_t y2 = v2.y;
    uint8_t z2 = v2.z;
    int16_t dx = abs(x2 - x1);
    int16_t dy = abs(y2 - y1);
    int16_t dz = abs(z2 - z1);

    int8_t xs = (x2 - x1) > 0 ? 1 : -1;
    int8_t ys = (y2 - y1) > 0 ? 1 : -1;
    int8_t zs = (z2 - z1) > 0 ? 1 : -1;

    int16_t p1, p2;

    // Driving axis is X-axis"
    if (dx >= dy && dx >= dz) {
        p1 = 2 * dy - dx;
        p2 = 2 * dz - dx;
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
            Vertex_i* v = (Vertex_i*) malloc(sizeof(Vertex_i));
            v->x = x1;
            v->y = y1;
            v->z = z1;

            array_list_append(vertices, v);
        }
    } 
 
    // Driving axis is Y-axis"
    else if (dy >= dx && dy >= dz) {
        p1 = 2 * dx - dy;
        p2 = 2 * dz - dy;
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
            Vertex_i* v = (Vertex_i*) malloc(sizeof(Vertex_i));
            v->x = x1;
            v->y = y1;
            v->z = z1;

            array_list_append(vertices, v);
        }
    } 
    
    // Driving axis is Z-axis"
    else {
        p1 = 2 * dy - dz;
        p2 = 2 * dx - dz;
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
            Vertex_i* v = (Vertex_i*) malloc(sizeof(Vertex_i));
            v->x = x1;
            v->y = y1;
            v->z = z1;

            array_list_append(vertices, v);
        }
    }
    return vertices;
}

/**
 * @brief Compare two vertices.
 * @param v1 The first vertex.
 * @param v2 The second vertex.
 * @return 1 if the vertices are the same, 0 otherwise.
*/
int compareVertices(const Vertex_i v1, const Vertex_i v2) {
    return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}

/**
 * @brief Hash a vertex.
 * @param v The vertex.
 * @return The hash of the vertex.
 * @note every vertex is hashed to a unique value.
*/
uint32_t hashVertex(const Vertex_i v) {
    return (uint32_t)(v.x << 16 | v.y << 8 | v.z);
}



/**
 * @brief Get all the vertices in a polyfon.
 * @param f The face.
 * @return The vertices in the face.
*/
ArrayList* getVerticesInFace(Face_i f) {
    ArrayList* vertices = array_list_new();
    ArrayList* line1 = getLineVertices(f.v1, f.v2);
    ArrayList* line2 = getLineVertices(f.v1, f.v3);

    for (unsigned int i = 0; i < line1->index; i++) {
        for (unsigned int j = 0; j < line2->index; j++) {
            Vertex_i* v1 = (Vertex_i*) array_list_get(line1, i);
            Vertex_i* v2 = (Vertex_i*) array_list_get(line2, j);
            ArrayList* line3 = getLineVertices(*v1, *v2);
            for (unsigned int k = 0; k < line3->index; k++) {
                Vertex_i* v = (Vertex_i*) array_list_get(line3, k);
                // This is gross and not my best work, but it works and I dont want to fix the hashset
                // linear search through the list
                int aleady_exists = 0;
                for (unsigned int l = 0; l < vertices->index; l++) {
                    Vertex_i* v_cmp = (Vertex_i*) array_list_get(vertices, l);
                    if (compareVertices(*v, *v_cmp)) {
                        aleady_exists = 1;
                        break;
                    }
                }
                if (aleady_exists) { continue; }

                // print_vertex_i(*v);
                Vertex_i* v_cpy = (Vertex_i*) malloc(sizeof(Vertex_i));
                v_cpy->x = v->x;
                v_cpy->y = v->y;
                v_cpy->z = v->z;
                array_list_append(vertices, v_cpy);
            }
            array_list_free(line3, free_vertex);
        }
    }
    array_list_free(line1, free_vertex);
    array_list_free(line2, free_vertex);

    return vertices;
}



/**
 * @brief Rasterize the faces.
 * @param faces The faces to rasterize. 
 * @param Z_BUFFER The Z buffer. All values initialized to MAX.
 * @param COLOR_BUFFER The color buffer. All values initialized to 0.
*/
void rasterize(ArrayList* faces, uint8_t** Z_BUFFER, uint8_t** COLOR_BUFFER) {
    // iterate through the faces
    // get all the blocks in the faces
    // iterate through all the blocks
    // determine depth of block
    // if block is closer then overwrite colorbuffer with block color at that pixel location

    for (unsigned int i=0; i<faces->index; i++) {
        Face_i* f = (Face_i*) array_list_get(faces, i);
        ArrayList* blocks = getVerticesInFace(*f);
        for (unsigned int j=0; j<blocks->index; j++) {
            Vertex_i* v = (Vertex_i*) array_list_get(blocks, j);
            // print_vertex_i(*v);
            if (v->z < Z_BUFFER[v->y][v->x]) {
                COLOR_BUFFER[v->y][v->x] = f->color.greyscale;
            }
        }
        array_list_free(blocks, free_vertex);
    }

}
