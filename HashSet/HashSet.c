#include "HashSet.h"

HashSet* hash_set_new() {
    Item* p_elements = (Item*) malloc(sizeof(Item) * INITIAL_SIZE);
    if (p_elements == NULL) return NULL;
    HashSet* hs = (HashSet*) malloc(sizeof(HashSet));
    hs->p_elements = p_elements;
    return hs;
}

HashSet* hash_set_resize(HashSet* hs) {
    Item* p_elements = (Item*) malloc(sizeof(Item) * hs->capactity * RESIZE_FACTOR);
    if (p_elements == NULL) return NULL;
    for (int i=0; i<hs->capactity; i++) {
        p_elements[i] = hs->p_elements[i];
    }
    free(hs->p_elements);
    hs->p_elements = p_elements;
    hs->capactity *= RESIZE_FACTOR;
    return hs;
}

uint32_t hash(uint32_t hs_size, int key) {
    return (uint32_t)key % hs_size;
}

void hash_set_insert(HashSet* hs, void* element, int key) {
    uint32_t hash_value = hash(hs->size, key);
    Item item = {key, element};

    while (1) {
        if (hs->p_elements[hash_value].value == NULL ||     // if the slot is empty
            hs->p_elements[hash_value].key == key) {    // if the key is already in the hashset
            hs->p_elements[hash_value] = item;
            break;
        }
        hash_value++;
        hs->collisions++;
    }
    hs->size++;
    // resize if too many collisions or too many elements
}

int hash_set_contains(HashSet* hs, int key) {
    uint32_t hash_value = hash(hs->size, key);
    while (1) {
        if (hs->p_elements[hash_value].value == NULL) return 0;
        if (hs->p_elements[hash_value].key == key) return 1;
        hash_value++;
    }
}

void* hash_set_get(HashSet* hs, int key) {
    uint32_t hash_value = hash(hs->size, key);
    while (1) {
        if (hs->p_elements[hash_value].value == NULL) return NULL;
        if (hs->p_elements[hash_value].key == key) return hs->p_elements[hash_value].value;
        hash_value++;
    }
}

void hash_set_remove(HashSet* hs, int key, void* free_func(void*)) {
    uint32_t hash_value = hash(hs->size, key);
    while (1) {
        if (hs->p_elements[hash_value].value == NULL) return;
        if (hs->p_elements[hash_value].key == key) {
            free_func(hs->p_elements[hash_value].value);
            hs->p_elements[hash_value].value = NULL;
            hs->size--;
            return;
        }
        hash_value++;
    }
}

void hash_set_free(HashSet* hs, void* free_func(void*)) {
    for (int i=0; i<hs->capactity; i++) {
        if (hs->p_elements[i].value != NULL) {
            free_func(hs->p_elements[i].value);
        }
    }
    free(hs->p_elements);
    free(hs);
    return;
}


