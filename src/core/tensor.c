#include "tensor.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constructor */
Tensor* create_tensor(size_t n_dims, const size_t *shape) {
    Tensor *tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor->n_dims = n_dims;
    tensor->shape = clone_array((void *) shape, n_dims, sizeof(size_t));
    tensor->steps = (size_t *) zeros(n_dims, sizeof(size_t));


        

    
}
