#ifndef TENSOR_H
#define TENSOR_H
#include <stdlib.h>

typedef struct {
    size_t n_dims;  
    size_t *shape; 
    size_t *steps;
    float *data;
} Tensor;

Tensor* create_tensor(size_t n_dims, const size_t *shape);

#endif
