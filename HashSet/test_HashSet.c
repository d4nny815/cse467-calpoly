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


// void test_hash_set_resize_get() {
//     HashSet* hs = hash_set_new();
//     int key1 = 1;
//     int key2 = 2;
//     int key3 = 3;
//     int key4 = 4;
//     int key5 = 5;
//     int key6 = 6;
//     int key7 = 7;
//     int key8 = 8;
//     int key9 = 9;
//     int key10 = 10;
//     int key11 = 11;

//     int element1 = 10;
//     int element2 = 20;
//     int element3 = 30;
//     int element4 = 40;
//     int element5 = 50;
//     int element6 = 60;
//     int element7 = 70;
//     int element8 = 80;
//     int element9 = 90;
//     int element10 = 100;
//     int element11 = 110;

//     hash_set_insert(hs, &element1, key1);
//     hash_set_insert(hs, &element2, key2);
//     hash_set_insert(hs, &element3, key3);
//     hash_set_insert(hs, &element4, key4);
//     hash_set_insert(hs, &element5, key5);
//     hash_set_insert(hs, &element6, key6);
//     hash_set_insert(hs, &element7, key7);
//     hash_set_insert(hs, &element8, key8);
//     hash_set_insert(hs, &element9, key9);
//     hash_set_insert(hs, &element10, key10);
//     hash_set_insert(hs, &element11, key11);

//     int* result1 = hash_set_get(hs, key1);
//     int* result2 = hash_set_get(hs, key2);
//     int* result3 = hash_set_get(hs, key3);
//     int* result4 = hash_set_get(hs, key4);
//     int* result5 = hash_set_get(hs, key5);
//     int* result6 = hash_set_get(hs, key6);
//     int* result7 = hash_set_get(hs, key7);
//     int* result8 = hash_set_get(hs, key8);
//     int* result9 = hash_set_get(hs, key9);
//     int* result10 = hash_set_get(hs, key10);
//     int* result11 = hash_set_get(hs, key11);

//     assert(hs->size == 11);
//     assert(*result1 == 10);
//     assert(*result2 == 20);
//     assert(*result3 == 30);
//     assert(*result4 == 40);
//     assert(*result5 == 50);
//     assert(*result6 == 60);
//     assert(*result7 == 70);
//     assert(*result8 == 80);
//     assert(*result9 == 90);
//     assert(*result10 == 100);
//     assert(*result11 == 110);

//     printf("test_hash_set_resize_get passed!\n");
// }


// void test_hash_set_resize_update() {
//     HashSet* hs = hash_set_new();
//     int key1 = 1;
//     int key2 = 2;
//     int key3 = 3;
//     int key4 = 4;
//     int key5 = 5;
//     int key6 = 6;
//     int key7 = 7;
//     int key8 = 8;
//     int key9 = 9;
//     int key10 = 10;
//     int key11 = 11;

//     int element1 = 10;
//     int element2 = 20;
//     int element3 = 30;
//     int element4 = 40;
//     int element5 = 50;
//     int element6 = 60;
//     int element7 = 70;
//     int element8 = 80;
//     int element9 = 90;
//     int element10 = 100;
//     int element11 = 110;

//     hash_set_insert(hs, &element1, key1);
//     hash_set_insert(hs, &element2, key2);
//     hash_set_insert(hs, &element3, key3);
//     hash_set_insert(hs, &element4, key4);
//     hash_set_insert(hs, &element5, key5);
//     hash_set_insert(hs, &element6, key6);
//     hash_set_insert(hs, &element7, key7);
//     hash_set_insert(hs, &element8, key8);
//     hash_set_insert(hs, &element9, key9);
//     hash_set_insert(hs, &element10, key10);
//     hash_set_insert(hs, &element11, key11);

//     int new_element1 = 1000;
//     int new_element2 = 2000;
//     int new_element3 = 3000;
//     int new_element4 = 4000;
//     int new_element5 = 5000;
//     int new_element6 = 6000;
//     int new_element7 = 7000;
//     int new_element8 = 8000;
//     int new_element9 = 9000;
//     int new_element10 = 10000;
//     int new_element11 = 11000;

//     hash_set_insert(hs, &new_element1, key1);
//     hash_set_insert(hs, &new_element2, key2);
//     hash_set_insert(hs, &new_element3, key3);
//     hash_set_insert(hs, &new_element4, key4);
//     hash_set_insert(hs, &new_element5, key5);
//     hash_set_insert(hs, &new_element6, key6);
//     hash_set_insert(hs, &new_element7, key7);
//     hash_set_insert(hs, &new_element8, key8);
//     hash_set_insert(hs, &new_element9, key9);
//     hash_set_insert(hs, &new_element10, key10);
//     hash_set_insert(hs, &new_element11, key11);

//     int* result1 = hash_set_get(hs, key1);
//     int* result2 = hash_set_get(hs, key2);
//     int* result3 = hash_set_get(hs, key3);
//     int* result4 = hash_set_get(hs, key4);
//     int* result5 = hash_set_get(hs, key5);
//     int* result6 = hash_set_get(hs, key6);
//     int* result7 = hash_set_get(hs, key7);
//     int* result8 = hash_set_get(hs, key8);
//     int* result9 = hash_set_get(hs, key9);
//     int* result10 = hash_set_get(hs, key10);
//     int* result11 = hash_set_get(hs, key11);

//     assert(hs->size == 11);
//     assert(*result1 == 1000);
//     assert(*result2 == 2000);
//     assert(*result3 == 3000);
//     assert(*result4 == 4000);
//     assert(*result5 == 5000);
//     assert(*result6 == 6000);
//     assert(*result7 == 7000);
//     assert(*result8 == 8000);
//     assert(*result9 == 9000);
//     assert(*result10 == 10000);
//     assert(*result11 == 11000);

//     printf("test_hash_set_resize_update passed!\n");
// }


// void test_hash_set_free() {
//     HashSet* hs = hash_set_new();
//     int key1 = 1;
//     int key2 = 2;
//     int key3 = 3;

//     int element1 = 10;
//     int element2 = 20;
//     int element3 = 30;

//     hash_set_insert(hs, &element1, key1);
//     hash_set_insert(hs, &element2, key2);
//     hash_set_insert(hs, &element3, key3);

//     hash_set_free(hs, NULL);

//     printf("test_hash_set_free passed!\n");
// }

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
    // test_hash_set_resize_get();
    // test_hash_set_resize_update();
    // test_hash_set_free();


    printf("All tests passed!\n");

    return 0;
}