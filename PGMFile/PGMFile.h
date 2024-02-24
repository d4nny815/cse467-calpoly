#ifndef PGMFILE_H
#define PGMFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>

void makePGMFile(const unsigned int width, const unsigned int height, const int max_greyscale, uint8_t** data, const char* filename);

#endif