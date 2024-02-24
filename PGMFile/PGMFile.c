#include "PGMFile.h"

void makePGMFile(const unsigned int width, const unsigned int height, const int max_greyscale, uint8_t** data, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) return;

    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", max_greyscale);

    for (unsigned int i=0; i<height; i++) {
        for (unsigned int j=0; j<width; j++) {
            fprintf(file, "%hhu ", data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return;
}