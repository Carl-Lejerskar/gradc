#ifndef TENSOR_H
#define TENSOR_H
#include <stdlib.h>

typedef struct {
    size_t n_dims;  
    size_t size;
    size_t *shape; 
    size_t *steps;
    float *data;
} Tensor;

Tensor* tensor_create(size_t n_dims, const size_t *shape);
Tensor* tensor_from_array(size_t n_dims, const size_t *shape, const float* values);

void tensor_free(Tensor* tensor);
void tensor_print(Tensor* tensor);

#endif
