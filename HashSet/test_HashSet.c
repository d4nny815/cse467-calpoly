#include <stdio.h>
#include <assert.h>
#include "HashSet.h"

void test_hash_set_insert() {
    HashSet* hs = hash_set_new();
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    hash_set_insert(hs, &element1, 1);
    hash_set_insert(hs, &element2, 2);
    hash_set_insert(hs, &element3, 3);

    assert(hash_set_contains(hs, 1) == 1);
    assert(hash_set_contains(hs, 2) == 1);
    assert(hash_set_contains(hs, 3) == 1);

    hash_set_free(hs, NULL);
    printf("hash_set_insert test passed\n");
}

void test_hash_set_contains() {
    HashSet* hs = hash_set_new();
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    hash_set_insert(hs, &element1, 1);
    hash_set_insert(hs, &element2, 2);
    hash_set_insert(hs, &element3, 3);

    assert(hash_set_contains(hs, 1) == 1);
    assert(hash_set_contains(hs, 2) == 1);
    assert(hash_set_contains(hs, 3) == 1);
    assert(hash_set_contains(hs, 4) == 0);

    hash_set_free(hs, NULL);
    printf("hash_set_contains test passed\n");
}

void test_hash_set_get() {
    HashSet* hs = hash_set_new();
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    hash_set_insert(hs, &element1, 1);
    hash_set_insert(hs, &element2, 2);
    hash_set_insert(hs, &element3, 3);

    assert(*(int*)hash_set_get(hs, 1) == 10);
    assert(*(int*)hash_set_get(hs, 2) == 20);
    assert(*(int*)hash_set_get(hs, 3) == 30);
    assert(hash_set_get(hs, 4) == NULL);

    hash_set_free(hs, NULL);
    printf("hash_set_get test passed\n");
}

void test_hash_set_remove() {
    HashSet* hs = hash_set_new();
    int element1 = 10;
    int element2 = 20;
    int element3 = 30;

    hash_set_insert(hs, &element1, 1);
    hash_set_insert(hs, &element2, 2);
    hash_set_insert(hs, &element3, 3);

    hash_set_remove(hs, 2, NULL);

    assert(hash_set_contains(hs, 1) == 1);
    assert(hash_set_contains(hs, 2) == 0);
    assert(hash_set_contains(hs, 3) == 1);

    hash_set_free(hs, NULL);
    printf("hash_set_remove test passed\n");
}

int main() {
    test_hash_set_insert();
    test_hash_set_contains();
    test_hash_set_get();
    test_hash_set_remove();

    printf("All tests passed!\n");

    return 0;
}