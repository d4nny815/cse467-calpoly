#ifndef OFF_FILE_H
#define OFF_FILE_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include "../ArrayList/ArrayList.h"

typedef struct Vertex {
    float x; // might be float
    float y;
    float z;
} Vertex;

typedef struct Face {
    Vertex p1;
    Vertex p2;
    Vertex p3;
} Face;

typedef struct ObjectDetails {
    int32_t vertices;
    int32_t faces;
    int32_t edges;
} ObjectDetails;

typedef struct OffFile {
    ObjectDetails* details;     // vertices, faces, edges
    ArrayList* vertices;          // list of vertices
    ArrayList* faces;           // list of faces
} OffFile;

OffFile* read_off_file(const char* filename);
int get_object_details(FILE* file, ObjectDetails* details);
ArrayList* get_vertices(FILE* file, int vertices_cnt);
ArrayList* get_faces(FILE* file, int faces_cnt);
void free_off_file(OffFile* off_file);
void* free_vertex(void* vertex);
void* free_face(void* face);





#endif // OFF_FILE_H