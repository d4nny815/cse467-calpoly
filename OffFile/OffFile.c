#include "OffFile.h"



/**
 * @brief Reads an OFF file and returns an OffFile struct containing the data.
 * @param filename The name of the file to read.
 * @return A pointer to the new OffFile struct.
*/
OffFile* read_off_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) return NULL;

    ObjectDetails* object_details = (ObjectDetails*)malloc(sizeof(ObjectDetails));
    int result = get_object_details(file, object_details);
    if (result != 0) {
        free(object_details);
        fclose(file);
        return NULL;
    }

    ArrayList* vertices = get_vertices(file, object_details->vertices);
    if (vertices == NULL) {
        free(object_details);
        fclose(file);
        return NULL;
    }

    // ArrayList* faces = get_faces(file, object_details->faces);

    OffFile* off_file = (OffFile*)malloc(sizeof(OffFile));
    off_file->details = object_details;
    off_file->vertices = vertices;
    // off_file->faces = faces;
    fclose(file);
    return off_file;
}


/**
 * @brief Reads the object details from the file and stores them in the ObjectDetails struct.
 * @param file The file to read from.
 * @param object_details The ObjectDetails struct to store the data in.
 * @return 0 on success, -1 on failure.
*/
int get_object_details(FILE* file, ObjectDetails* object_details) {
    const int LINE_SIZE = 256;
    char line[LINE_SIZE];
    if (fgets(line, LINE_SIZE, file) == NULL) return -1;
    if (strcmp(line, "OFF\n") != 0) return -1;
    if (fgets(line, LINE_SIZE, file) == NULL) return -1;
    int num_vertices, num_faces, num_edges;
    if (sscanf(line, "%d %d %d", &num_vertices, &num_faces, &num_edges) != 3) return -1;
    object_details->vertices = num_vertices;
    object_details->faces = num_faces;
    object_details->edges = num_edges;
    return 0;
}


/**
 * @brief Reads the vertices from the off file and stores them in an ArrayList.
 * @param file The file to read from. Assume the file pointer is at the correct position.
 * @param vertices_cnt The number of vertices to read.
 * @return A pointer to the new ArrayList containing the vertices.
*/
ArrayList* get_vertices(FILE* file, int vertices_cnt) {
    char* line = NULL;
    size_t len = 0;

    ArrayList* vertices = array_list_new();
    for (int i=0; i<vertices_cnt; i++) {
        Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
        if (getline(&line, &len, file) == -1) {
            array_list_free(vertices, free_vertex);
            free(line);
            return NULL;
        }
        if (sscanf(line, "%f %f %f", &vertex->x, &vertex->y, &vertex->z) != 3) {
            array_list_free(vertices, free_vertex);
            free(line);
            return NULL;
        }
        array_list_append(vertices, (void*)vertex);
    }
    free(line);
    return vertices;
}

ArrayList* get_faces(FILE* file, int faces_cnt) {
    // TODO: Implement this function
    return NULL;
}

/**
 * @brief function pointer to free a vertex
 * @param vertex The vertex to free.
*/
void* free_vertex(void* vertex) {
    free(vertex);
    return NULL;
}

/**
 * @brief function pointer to free a face
 * @param face The face to free.
*/
void* free_face(void* face) {
    free(face);
    return NULL;
}

void free_off_file(OffFile* off_file) {
    array_list_free(off_file->vertices, free_vertex);
    // array_list_free(off_file->faces, free_face);
    free(off_file->details);
    free(off_file);
}


