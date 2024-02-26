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
//     ArrayList* vertices = array_list_new();
//     ArrayList* line1 = getLineVertices(f.v1, f.v2);
//     ArrayList* line2 = getLineVertices(f.v1, f.v3);

//     struct buffer {
//         Vertex_i* v;
//         int valid;
//     };

//     struct buffer* buffer = (struct buffer*) malloc(MAX_POLYGON_BUFFER * sizeof(struct buffer));
//     int num_unrolls = 8;
//     int remainder = MAX_POLYGON_BUFFER % num_unrolls;
//     for (int i = 0; i < MAX_POLYGON_BUFFER; i+= num_unrolls) {
//         buffer[i + 0].v = NULL;
//         buffer[i + 1].v = NULL;
//         buffer[i + 2].v = NULL;
//         buffer[i + 3].v = NULL;
//         buffer[i + 4].v = NULL;
//         buffer[i + 5].v = NULL;
//         buffer[i + 6].v = NULL;
//         buffer[i + 7].v = NULL;
//         buffer[i + 0].valid = 0;
//         buffer[i + 1].valid = 0;
//         buffer[i + 2].valid = 0;
//         buffer[i + 3].valid = 0;
//         buffer[i + 4].valid = 0;
//         buffer[i + 5].valid = 0;
//         buffer[i + 6].valid = 0;
//         buffer[i + 7].valid = 0;
//     }
//     for (int i = MAX_POLYGON_BUFFER - remainder; i < MAX_POLYGON_BUFFER; i++) {
//         buffer[i].v = NULL;
//         buffer[i].valid = 0;
//     }
    

//     for (unsigned int i = 0; i < line1->index; i++) {
//         for (unsigned int j = 0; j < line2->index; j++) {
//             Vertex_i* v1 = (Vertex_i*) array_list_get(line1, i);
//             Vertex_i* v2 = (Vertex_i*) array_list_get(line2, j);
//             ArrayList* line3 = getLineVertices(*v1, *v2);
//             for (unsigned int k = 0; k < line3->index; k++) {
//                 Vertex_i* v = (Vertex_i*) array_list_get(line3, k);
                
//                 Vertex_i* v_cpy = (Vertex_i*) malloc(sizeof(Vertex_i));
//                 v_cpy->x = v->x;
//                 v_cpy->y = v->y;
//                 v_cpy->z = v->z;

//                 uint32_t hash = hashVertex(*v);
//                 buffer[hash].v = v_cpy;
//                 buffer[hash].valid = 1;
                
//             }
//             array_list_free(line3, free_vertex);
//         }
//     }
//     array_list_free(line1, free_vertex);
//     array_list_free(line2, free_vertex);


//     for (int i=0; i<MAX_POLYGON_BUFFER; i+=num_unrolls) {
//         if (buffer[i + 0].valid) { array_list_append(vertices, buffer[i + 0].v); }
//         if (buffer[i + 1].valid) { array_list_append(vertices, buffer[i + 1].v); }
//         if (buffer[i + 2].valid) { array_list_append(vertices, buffer[i + 2].v); }
//         if (buffer[i + 3].valid) { array_list_append(vertices, buffer[i + 3].v); }
//         if (buffer[i + 4].valid) { array_list_append(vertices, buffer[i + 4].v); }
//         if (buffer[i + 5].valid) { array_list_append(vertices, buffer[i + 5].v); }
//         if (buffer[i + 6].valid) { array_list_append(vertices, buffer[i + 6].v); }
//         if (buffer[i + 7].valid) { array_list_append(vertices, buffer[i + 7].v); }
//     }
//     for (int i = MAX_POLYGON_BUFFER - remainder; i < MAX_POLYGON_BUFFER; i++) {
//         if (buffer[i].valid) { array_list_append(vertices, buffer[i].v); }
//     }


    // free(buffer);
    // return vertices;

    ArrayList* vertices = array_list_new();
    ArrayList* line1 = getLineVertices(f.v1, f.v2);
    ArrayList* line2 = getLineVertices(f.v1, f.v3);
    int already_exists;

    for (unsigned int i = 0; i < line1->index; i++) {
        for (unsigned int j = 0; j < line2->index; j++) {
            Vertex_i* v1 = (Vertex_i*) array_list_get(line1, i);
            Vertex_i* v2 = (Vertex_i*) array_list_get(line2, j);
            ArrayList* line3 = getLineVertices(*v1, *v2);
            for (unsigned int k = 0; k < line3->index; k++) {
                Vertex_i* v = (Vertex_i*) array_list_get(line3, k);
                
                // This is gross and not my best work, but it works and I dont want to fix the hashset
                // linear search through the list
                already_exists = 0;
                for (unsigned int l = 0; l < vertices->index; l++) {
                    Vertex_i* v_cmp = (Vertex_i*) array_list_get(vertices, l);
                    if (compareVertices(*v, *v_cmp)) {
                        already_exists = 1;
                        break;
                    }
                }
                if (already_exists) { continue; }

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
void rasterize(ArrayList* faces, uint8_t* Z_BUFFER, uint8_t* COLOR_BUFFER) {
    uint16_t pixel_location;
    for (unsigned int i=0; i<faces->index; i++) {
        Face_i* f = (Face_i*) array_list_get(faces, i);
        ArrayList* blocks = getVerticesInFace(*f);
        for (unsigned int j=0; j<blocks->index; j++) {
            Vertex_i* v = (Vertex_i*) array_list_get(blocks, j);
            pixel_location = v->y * DISPLAY_WIDTH + v->x;
            if (v->z <= Z_BUFFER[pixel_location]) {
                Z_BUFFER[pixel_location] = v->z;
                COLOR_BUFFER[pixel_location] = f->color.greyscale;
            }
        }
        // printf("Rasterized face %d of %d\n", i, faces->index);
        array_list_free(blocks, free_vertex);
    }
    return;
}

void print_color_buffer(uint8_t* COLOR_BUFFER) {
    for (int i = 0; i < FRAME_BUFFER_SIZE; i++) {
        printf("%hhu ", COLOR_BUFFER[i]);
        if (i % DISPLAY_WIDTH == 0) {
            printf("\n");
        }
    }
}

void parallel_rasterize(ArrayList* faces, uint8_t* Z_BUFFER, uint8_t* COLOR_BUFFER, int num_processes) {
    if (num_processes == 1) {
        rasterize(faces, Z_BUFFER, COLOR_BUFFER);
        return;
    }
    
    
    int num_faces = faces->index;
    int faces_per_process = num_faces / num_processes;
    int faces_remaining = num_faces % num_processes;
    int start = 0;
    int end = faces_per_process;
    int pids[num_processes];
    int fd_z[num_processes][2];
    int fd_c[num_processes][2];

    // struct to hold the data for the processes
    typedef struct {
        ArrayList* faces;
        uint8_t* Z_BUFFER;
        uint8_t* COLOR_BUFFER;
    } ProcessData;

    ProcessData data[num_processes];

    // make the pipes
    for (int i = 0; i < num_processes; i++) {
        if (pipe(fd_c[i]) == -1) {
            perror("pipe");
            exit(1);
        }
        if (pipe(fd_z[i]) == -1) {
            perror("pipe");
            exit(1);
        }
    }

    // distribute the faces to the processes
    for (int i = 0; i < num_processes; i++) {
        data[i].faces = array_list_new();
        for (int j = start; j < end; j++) {
            Face_i* f = (Face_i*) array_list_get(faces, j);
            Face_i* f_cpy = (Face_i*) malloc(sizeof(Face_i));
            f_cpy->v1 = f->v1;
            f_cpy->v2 = f->v2;
            f_cpy->v3 = f->v3;
            f_cpy->normal = f->normal;
            f_cpy->color = f->color;
            array_list_append(data[i].faces, f_cpy);
        }

        data[i].Z_BUFFER = (uint8_t*) malloc(FRAME_BUFFER_SIZE * sizeof(uint8_t));
        data[i].COLOR_BUFFER = (uint8_t*) malloc(FRAME_BUFFER_SIZE * sizeof(uint8_t));
        memset(data[i].Z_BUFFER, DEPTH - 1, FRAME_BUFFER_SIZE * sizeof(uint8_t));
        memset(data[i].COLOR_BUFFER, 0, FRAME_BUFFER_SIZE * sizeof(uint8_t));

        start = end;
        if (i < faces_remaining) {
            end += faces_per_process + 1;
        } else {
            end += faces_per_process;
        }
    }
    
    // fork the processes and have change the Z_BUFFER and COLOR_BUFFER in the structs
    for (int i = 0; i < num_processes; i++) {
        if ((pids[i] = fork()) == 0) {
            rasterize(data[i].faces, data[i].Z_BUFFER, data[i].COLOR_BUFFER);
            int w = write(fd_c[i][1], data[i].COLOR_BUFFER, FRAME_BUFFER_SIZE * sizeof(uint8_t));
            if (w == -1) {
                perror("write");
                exit(1);
            }
            w = write(fd_z[i][1], data[i].Z_BUFFER, FRAME_BUFFER_SIZE * sizeof(uint8_t));
            if (w == -1) {
                perror("write");
                exit(1);
            }
            exit(0);
            
        }
    }

    // wait for the processes to finish
    for (int i = 0; i < num_processes; i++) {
        waitpid(pids[i], NULL, 0);
    }

    // combine the Z buffers
    for (int i = 0; i < num_processes; i++) {
        uint8_t* Z_BUFFER_i = (uint8_t*) malloc(FRAME_BUFFER_SIZE * sizeof(uint8_t));
        int r = read(fd_z[i][0], Z_BUFFER_i, FRAME_BUFFER_SIZE * sizeof(uint8_t));
        if (r == -1) {
            perror("read");
            exit(1);
        }
        uint8_t* COLOR_BUFFER_i = (uint8_t*) malloc(FRAME_BUFFER_SIZE * sizeof(uint8_t));
        r = read(fd_c[i][0], COLOR_BUFFER_i, FRAME_BUFFER_SIZE * sizeof(uint8_t));
        if (r == -1) {
            perror("read");
            exit(1);
        }
        for (int j = 0; j < FRAME_BUFFER_SIZE; j++) {
            if (Z_BUFFER_i[j] < Z_BUFFER[j]) {
                Z_BUFFER[j] = Z_BUFFER_i[j];
                COLOR_BUFFER[j] = COLOR_BUFFER_i[j];
            }

        }
        free(Z_BUFFER_i);
        free(COLOR_BUFFER_i);

    }


    // free the memory
    for (int i = 0; i < num_processes; i++) {
        array_list_free(data[i].faces, free_face);
        free(data[i].Z_BUFFER);
        free(data[i].COLOR_BUFFER);
    }



    return;
}
