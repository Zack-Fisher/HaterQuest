#include "array.h"

void push(void *array, int length, size_t element_size, void *new_element) {
    int i = 0;
    char *ptr = array;
    while (i < length && memcmp(ptr + i * element_size, new_element, element_size) != 0) {
        i++;
    }

    if (i < length) {
        memcpy(ptr + i * element_size, new_element, element_size);
        printf("New element added at index %d\n", i);
    } else {
        printf("Array is full, new element not added.\n");
    }
}