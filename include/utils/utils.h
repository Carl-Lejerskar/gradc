#ifndef UTILS_H
#define UTILS_H
#include <stddef.h>

/* Clone an array on the heap */
void* clone_array(const void* arr, size_t len, size_t byte_size);
/* Create a zeros array on the heap */
void* zeros(size_t len, size_t byte_size);
/* Print a float array */
void print_array(const float* arr, size_t len);

#endif
