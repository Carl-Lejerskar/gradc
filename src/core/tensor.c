#include "tensor.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constructor */
Tensor* tensor_create(size_t n_dims, const size_t *shape) {

    Tensor *tensor = (Tensor*) malloc(sizeof(Tensor));

    if (!tensor) {
        perror("malloc failed on tensor");
        return NULL;
    }

    tensor->n_dims = n_dims;
    tensor->shape = clone_array((void *) shape, n_dims, sizeof(size_t));
    tensor->steps = (size_t *) zeros(n_dims, sizeof(size_t));

    if (!tensor->steps) {
        perror("malloc failed on tensor->steps");
        free(tensor->shape);
        free(tensor);
        return NULL;
    }


    // step_size starts as 1 as in the deepest dim you iterate element by element
    size_t step_size = 1;
    if (n_dims > 0) {
        size_t i = n_dims;
        while (i > 0) {
            // start at deepest dim
            i--;
            tensor->steps[i] = step_size;
            // multiply by dim's respective shape 
            // as that is how much the next, outer dim needs to step
            step_size *= shape[i];

        }
    }
    
    tensor->size = step_size;

    // init data w/ zeros
    tensor->data = zeros(step_size, sizeof(float));

    if (!tensor->data) {
        perror("malloc failed on tensor->data");
        tensor_free(tensor);
        return NULL;
    }

    // initialize data w/ zeros

    return tensor;
}

Tensor* tensor_from_array(size_t n_dims, const size_t *shape, const float* values) {
    Tensor* tensor = tensor_create(n_dims, shape);

    if (!tensor) {
        fprintf(stderr, "Tensor creation failed when initializing from array...");
    }

    for (size_t i = 0; i < tensor->size; i++) {
        tensor->data[i] = values[i];
    }

    return tensor;
}

void tensor_free(Tensor* tensor) {
    if (tensor) {
        free(tensor->shape);
        free(tensor->steps);
        free(tensor);
    }
}

void tensor_print(Tensor* tensor) {
    if (!tensor || !tensor->data) {
        printf("You're trying to print an empty tensor...");
        return;

    }

    if (tensor->n_dims > 2) {
        printf("Printing is only supported for n_dims <= 2...");
        return;
    }

    if (tensor->n_dims ==  0) {
        printf("%.2f\n", tensor->data[0]);
        return;
    }

    if (tensor->n_dims == 1) {
        print_array(tensor->data, tensor->shape[0]);
        return;
    }

    if (tensor->n_dims == 2) {
        printf("[\n");
        for (size_t i = 0; i < tensor->shape[0]; i++) {
            printf(" ");
            print_array(tensor->data + i * tensor->steps[0], tensor->shape[1]);
        }
        printf("]\n");
        return;
    }
}
