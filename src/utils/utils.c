#include <stddef.h>
#include <stdlib.h>

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