#include "HashSet.h"

HashSet* hash_set_new() {
    Item* p_elements = (Item*) malloc(sizeof(Item) * INITIAL_SIZE);
    if (p_elements == NULL) return NULL;
    HashSet* hs = (HashSet*) malloc(sizeof(HashSet));
    hs->p_elements = p_elements;
    hs->size = 0;
    hs->capactity = INITIAL_SIZE;
    hs->collisions = 0;
    return hs;
}

HashSet* hash_set_resize(HashSet* hs) {
    HashSet* new_hs = hash_set_new();
    if (new_hs == NULL) return NULL;
    Item* items = hash_get_items(hs);
    if (items == NULL) return NULL;
    new_hs->capactity = hs->capactity * RESIZE_FACTOR;
    int i = 0;
    while (items[i].value != NULL) {
        hash_set_insert(new_hs, items[i].value, items[i].key);
        i++;
    }
    free(items);
    free(hs->p_elements);
    hs->p_elements = new_hs->p_elements;
    hs->capactity = new_hs->capactity;
    free(new_hs);
    return hs;
}

Item* hash_get_items(HashSet* hs) {
    Item* items = (Item*) malloc(sizeof(Item) * hs->size);
    if (items == NULL) return NULL;
    int j = 0;
    for (uint32_t i=0; i<hs->capactity; i++) {
        if (hs->p_elements[i].value != NULL) {
            items[j] = hs->p_elements[i];
            j++;
        }
    }
    return items;
}

uint32_t hash(uint32_t hs_cap, int key) {
    return (uint32_t)key % hs_cap;
}

void hash_set_insert(HashSet* hs, void* element, int key) {
    uint32_t hash_value = hash(hs->capactity, key);
    Item item = {key, element};

    while (1) {
        Item ele = hs->p_elements[hash_value];
        if (ele.value == NULL) {
            hs->p_elements[hash_value] = item;
            hs->size++;
            break;
        } 
        else if (ele.key == key) {
            hs->p_elements[hash_value] = item;
            break;
        }
        hash_value++;
        hs->collisions++;
    }
    
    // resize if too many collisions or too many elements
    if (hs->collisions > hs->size / 2 || hs->size > hs->capactity / 2) {
        hs = hash_set_resize(hs);
    }
}

int hash_set_contains(HashSet* hs, int key) {
    uint32_t hash_value = hash(hs->capactity, key);
    while (1) {
        Item ele = hs->p_elements[hash_value];
        if (ele.value == NULL) return 0;
        if (ele.key == key) return 1;
        hash_value++;
    }
}

void* hash_set_get(HashSet* hs, int key) {
    uint32_t hash_value = hash(hs->capactity, key);
    while (1) {
        if (hs->p_elements[hash_value].value == NULL) return NULL;
        if (hs->p_elements[hash_value].key == key) return hs->p_elements[hash_value].value;
        hash_value++;
    }
}

void hash_set_remove(HashSet* hs, int key, void* free_func(void*)) {
    uint32_t hash_value = hash(hs->size, key);
    if (hs->p_elements[hash_value].value == NULL) return;
    else {
        if (free_func != NULL) free_func(hs->p_elements[hash_value].value);
        hs->p_elements[hash_value].value = NULL;
        hs->size--;
    }
}

void hash_set_free(HashSet* hs, void* free_func(void*)) {
        for (uint32_t i=0; i<hs->capactity; i++) {
            if (hs->p_elements[i].value != NULL) {
                if (free_func != NULL) free_func(hs->p_elements[i].value);
                hs->p_elements[i].value = NULL;
            }
    }
    free(hs->p_elements);
    free(hs);
    return;
}


