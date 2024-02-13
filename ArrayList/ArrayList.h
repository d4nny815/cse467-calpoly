#ifndef  ARRAYLIST_H
#define ARRAYLIST_H
#define INITIAL_SIZE 500
#define RESIZE_FACTOR 2
#include <stdlib.h>

typedef struct {
    void** p_elements;
    unsigned int size;
    unsigned int index;
} ArrayList;

ArrayList* array_list_new();
int array_list_append(ArrayList* array_list, void* element);
int array_list_insert(ArrayList* array_list, void* element, int index);
int array_list_replace(ArrayList* array_list, void* element, int index);
int array_list_resize(ArrayList* array_list);
void* array_list_get(ArrayList* array_list, int index);
void array_list_remove(ArrayList* array_list, int index);
// void array_list_free(ArrayList* array_list, void (*free_func)(void*));
void array_list_free(ArrayList* array_list, void* free_func(void*));

#endif