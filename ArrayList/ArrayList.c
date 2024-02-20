#include "ArrayList.h"

/**
 * @brief Creates a new ArrayList of size INITIAL_SIZE containing Demographics pointers.
 * @return A pointer to the new ArrayList.
*/
ArrayList* array_list_new() {
    ArrayList* arr_list = (ArrayList*) malloc(sizeof(ArrayList));
    if (arr_list == NULL) return NULL;
    void** ptr = (void**)malloc(INITIAL_SIZE * sizeof(void*));
    if (ptr == NULL) return NULL;
    arr_list->p_elements = ptr;
    arr_list->size = INITIAL_SIZE;
    arr_list->index = 0;
    return arr_list;
}

/**
 * @brief Adds a Demographics pointer to the end of the ArrayList.
 * @param array_list The ArrayList to add to.
 * @param element The Demographics pointer to add.
 * @return 0 on success, -1 on failure.
*/
int array_list_append(ArrayList* array_list, void* element) {
    if (array_list->index >= array_list->size) {
        if (array_list_resize(array_list)) return -1;
    }
    array_list->p_elements[array_list->index] = element;
    array_list->index++;
    return 0;
}

/**
 * @brief Inserts a Demographics pointer at the specified index. Moves all elements after the index up by one.
 * @param array_list The ArrayList to insert into.
 * @param element The Demographics pointer to insert.
 * @param index The index to insert at.
 * @return 0 on success, -1 on failure.
*/
int array_list_insert(ArrayList* array_list, void* element, int index) {
    if (index < 0 || (unsigned int)index > array_list->size) return -1; 
    if (array_list->index == array_list->size - 1) { 
        if (array_list_resize(array_list)) return -1;
    }
    for (int i=array_list->index; i>index; i--) {
        array_list->p_elements[i] = array_list->p_elements[i-1];
    }
    array_list->p_elements[index] = element;
    array_list->index++;
    return 0;
}

/**
 * @brief Replaces the Demographics pointer at the specified index.
 * @param array_list The ArrayList to replace in.
 * @param element The Demographics pointer to replace with.
 * @param index The index to replace at.
 * @return 0 on success, -1 on failure.
*/
int array_list_replace(ArrayList* array_list, void* element, int index) {
    if (index < 0 || (unsigned int)index > array_list->size) return -1;
    array_list->p_elements[index] = element;
    return 0;
}


/**
 * @brief Resizes the ArrayList to be twice as large.
 * @param array_list The ArrayList to resize.
 * @return 0 on success, -1 on failure.
*/
int array_list_resize(ArrayList* array_list) {
    array_list->size *= RESIZE_FACTOR;
    void** ptr = (void**)realloc(array_list->p_elements, array_list->size * sizeof(void*));
    if (ptr == NULL) return -1;
    array_list->p_elements = ptr;
    return 0;
}

/**
 * @brief Gets the Demographics pointer at the specified index.
 * @param array_list The ArrayList to get from.
 * @param index The index to get from.
 * @return The Demographics pointer at the specified index.
*/
void* array_list_get(ArrayList* array_list, int index) {
    if (index < 0) return NULL;
    return array_list->p_elements[index];
}

/**
 * @brief Removes the Demographics pointer at the specified index. Moves all elements after the index down by one.
 * @param array_list The ArrayList to remove from.
 * @param index The index to remove from.
*/
void array_list_remove(ArrayList* array_list, int index) {
    if (index < 0 || (unsigned int)index > array_list->index) return;
    for (size_t i=index; i<array_list->index; i++) {
        array_list->p_elements[i] = array_list->p_elements[i+1];
    }
    array_list->index--;
    return;
}


/**
 * @brief Frees the ArrayList and all of its elements.
 * @param array_list The ArrayList to free.
 * @param free_func The function to free the elements with.
 * @return void
*/
// void array_list_free(ArrayList* array_list, void (*free_func)(void*)) {
//     for (size_t i=0; i<array_list->index; i++) {
//         free_func(array_list->p_elements[i]);
//     }
//     free(array_list->p_elements);
//     free(array_list);
//     return;
// }

void array_list_free(ArrayList* array_list, void* free_func(void*)) {
    for (size_t i=0; i<array_list->index; i++) {
        if (free_func != NULL) free_func(array_list->p_elements[i]);
    }
    free(array_list->p_elements);
    free(array_list);
    return;
}