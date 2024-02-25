#include <stdio.h>
#include <assert.h>
#include "HashSet.h"


void test_hash_set_new() {
    HashSet* hs = hash_set_new();
    assert(hs->capactity == 10);
    assert(hs->size == 0);
    assert(hs->collisions == 0);

    printf("test_hash_set_new passed!\n");
    hash_set_free(hs, NULL);
}

void test_hash_set_insert() {
    HashSet* hs = hash_set_new();
    int key1 = 1;
    int key2 = 2;
    int key3 = 3;

    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    hash_set_insert(hs, &element1, key1);
    hash_set_insert(hs, &element2, key2);
    hash_set_insert(hs, &element3, key3);

    assert(hs->size == 3);

    printf("test_hash_set_insert passed!\n");
    hash_set_free(hs, NULL);
}


void test_hash_set_contains() {
    HashSet* hs = hash_set_new();

    int keys[] = {1, 2, 3};
    int elements[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        hash_set_insert(hs, &(elements[i]), keys[i]);
    }


    int results[] = {1, 1, 1};
    for (int i = 0; i < 3; i++) {
        int result = hash_set_contains(hs, keys[i]);
        assert(result == results[i]);
    }

    assert(hash_set_contains(hs, 4) == 0);
    assert(hs->size == 3);


    printf("test_hash_set_contains passed!\n");
    hash_set_free(hs, NULL);
}


void test_hash_set_get() {
    HashSet* hs = hash_set_new();
    
    int keys[] = {1, 2, 3};
    int elements[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        hash_set_insert(hs, &elements[i], keys[i]);
    }

    int results[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        int* result = hash_set_get(hs, keys[i]);
        assert(*result == results[i]);
    }


    printf("test_hash_set_get passed!\n");
    hash_set_free(hs, NULL);
}

void test_hash_set_get_items() {
    HashSet* hs = hash_set_new();

    int keys[] = {1, 2, 3};
    int elements[] = {10, 20, 30};

    Item items[3];

    for (int i = 0; i < 3; i++) {
        hash_set_insert(hs, &elements[i], keys[i]);
        items[i].key = keys[i];
        items[i].value = &elements[i];
    }

    Item* result = hash_get_items(hs);
    for (int i = 0; i < 3; i++) {
        assert(result[i].key == items[i].key);
        assert(result[i].value == items[i].value);
    }

    printf("test_hash_set_get_items passed!\n");
    free(result);
    hash_set_free(hs, NULL);
}


void test_hash_set_update() {
    HashSet* hs = hash_set_new();
    
    int keys[] = {1, 2, 3};
    int elements[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        hash_set_insert(hs, &elements[i], keys[i]);
    }

    int expected[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        int* result = hash_set_get(hs, keys[i]);
        assert(*result == expected[i]);
    }

    int new_elements[] = {100, 200, 300};
    for (int i = 0; i < 3; i++) {
        hash_set_insert(hs, &new_elements[i], keys[i]);
    }

    int new_expected[] = {100, 200, 300};
    for (int i = 0; i < 3; i++) {
        int* result = hash_set_get(hs, keys[i]);
        assert(*result == new_expected[i]);
    }


    printf("test_hash_set_update passed!\n");
    hash_set_free(hs, NULL);
}


void test_hash_set_resize() {
    HashSet* hs = hash_set_new();
    int keys[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int elements[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    uint32_t original_capacity = hs->capactity;

    for (int i = 0; i < 10; i++) {
        hash_set_insert(hs, &elements[i], keys[i]);
    }

    for (int i = 0; i < 10; i++) {
        int* result = (int*) hash_set_get(hs, keys[i]);
        assert(*result == elements[i]);
    }

    assert(hs->capactity == original_capacity * RESIZE_FACTOR);

    printf("test_hash_set_resize passed!\n");
    hash_set_free(hs, NULL);
}


void test_hash_set_remove() {
    HashSet* hs = hash_set_new();
    int keys[] = {1, 2, 3};
    int elements[] = {10, 20, 30}; 

    for (int i = 0; i < 3; i++) {
        hash_set_insert(hs, &elements[i], keys[i]);
    }

    hash_set_remove(hs, 1, NULL);

    assert(hs->size == 2);
    assert(hash_set_contains(hs, 1) == 0);

    printf("test_hash_set_remove passed!\n");
}





// TODO: test hash_set_free with free_func
// TODO: test hash_set_free with free_func and structs
// TODO: test hash_set_remove with free_func



int main() {
    test_hash_set_new();
    test_hash_set_insert();
    test_hash_set_contains();
    test_hash_set_get();
    test_hash_set_get_items();
    test_hash_set_update();
    test_hash_set_resize();
    test_hash_set_remove();


    printf("All tests passed!\n");

    return 0;
}