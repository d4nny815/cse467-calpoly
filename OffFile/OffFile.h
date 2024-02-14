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
#include "../Primitives/Primitives.h"

typedef struct ObjectDetails {
    int32_t vertices;
    int32_t faces;
    int32_t edges;
} ObjectDetails;

typedef struct OffFile {
    ObjectDetails details;   // vertices, faces, edges
    ArrayList* vertices;     // list of vertices
    ArrayList* faces;        // list of faces
} OffFile;

OffFile* read_off_file(const char* filename);
int get_object_details(FILE* file, ObjectDetails* details);
ArrayList* get_vertices(FILE* file, int vertices_cnt);
ArrayList* get_faces(FILE* file, int faces_cnt, ArrayList* vertices);

void free_off_file(OffFile* off_file);

#endif // OFF_FILE_H