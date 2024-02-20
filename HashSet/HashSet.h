#ifndef HASHSET_H
#define HASHSET_H
#define INITIAL_SIZE 10
#define RESIZE_FACTOR 2

#include <stdlib.h>
#include <stdint.h>

typedef struct Item {
    int key;
    void* value;   
} Item;

typedef struct HashSet {
    Item* p_elements;
    uint32_t size;
    uint32_t capactity;
    uint32_t collisions;
} HashSet;


HashSet* hash_set_new();
HashSet* hash_set_resize(HashSet* hs);
Item* hash_get_items(HashSet* hs);
uint32_t hash(uint32_t hs_size, int key);
void hash_set_insert(HashSet* hs, void* element, int key);
int hash_set_contains(HashSet* hs, int key);
void* hash_set_get(HashSet* hs, int key);
void hash_set_remove(HashSet* hs, int key, void* free_func(void*)); 
void hash_set_free(HashSet* free, void* free_func(void*));



#endif