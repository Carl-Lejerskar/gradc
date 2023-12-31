#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Clone an array on the heap */
void* clone_array(const void* arr, size_t len, size_t byte_size) {
    void *clone = malloc(len*byte_size);
    memcpy(clone, arr, len*byte_size);
    return clone;
}

/* Get a fresh array of 0s */
void* zeros(size_t len, size_t byte_size) {
    void* arr = malloc(len * byte_size);
    memset(arr, 0, len * byte_size);
    return arr;
}

/* Print a float array */ 
void print_array(const float* arr, size_t len) {
    printf("[");
    for (size_t i=0; i < len; i++) {
        if (i != len - 1) {
            printf("%.2f, ", arr[i]);
        } else {
            printf("%.2f", arr[i]);
        }
    }
    printf("]\n");
}

bool array_equals(const void* a, const void* b, size_t size) {
    const unsigned char* a_bytes = a;
    const unsigned char* b_bytes = b;

    for (size_t i = 0; i < size; i++) {
        if (a_bytes[i] != b_bytes[i]) {
            return false;
        }
    }
    return true;
}

