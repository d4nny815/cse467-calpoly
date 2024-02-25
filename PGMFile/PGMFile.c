#include "PGMFile.h"


/**
 * @brief Create a PGM file from the given data
 * @param width The width of the image
 * @param height The height of the image
 * @param max_greyscale The maximum greyscale value
 * @param data The data to write to the file
 * @param filename The name of the file to write to
*/
void makePGMFile(const unsigned int width, const unsigned int height, const int max_greyscale, uint8_t* data, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) return;

    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", max_greyscale);

    for (unsigned int i=0; i<height; i++) {
        for (unsigned int j=0; j<width; j++) {
            fprintf(file, "%d ", data[i * width + j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return;
}