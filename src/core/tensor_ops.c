#include "utils.h"
#include <stdio.h>
#include "tensor.h"
#include "tensor_ops.h"

Tensor* tensor_add(const Tensor* a, const Tensor* b) {
    // ensure the tensors match
    // if checks are expensive remove..
    if (a->size != b -> size || !array_equals(a->shape, b->shape, a->size)) {
        fprintf(stderr, "Mismatched tensors on add!");
    }

    Tensor* tensor = tensor_create(a->n_dims, a->shape);

    for (size_t i = 0; i < a->size; i++) {
        tensor->data[i] = a->data[i] + b->data[i];
    }

    return tensor;
}

// duplicate of tensor_add for efficiency over tensor_add(a, neg(b))
Tensor* tensor_subtract(const Tensor* a, const Tensor* b) {
    // if checks are expensive remove..
    if (a->size != b -> size || !array_equals(a->shape, b->shape, a->size)) {
        fprintf(stderr, "Mismatched tensors on add!");
    }

    Tensor* tensor = tensor_create(a->n_dims, a->shape);

    for (size_t i = 0; i < a->size; i++) {
        tensor->data[i] = a->data[i] - b->data[i];
    }

    return tensor;
}


Tensor* tensor_multiply(const Tensor* a, const Tensor* b) {
    // if checks are expensive remove..
    if (a->size != b -> size || !array_equals(a->shape, b->shape, a->size)) {
        fprintf(stderr, "Mismatched tensors on add!");
    }

    Tensor* tensor = tensor_create(a->n_dims, a->shape);

    for (size_t i = 0; i < a->size; i++) {
        tensor->data[i] = a->data[i] * b->data[i];
    }

    return tensor;
}


Tensor* tensor_dot(const Tensor* a, const Tensor* b) {
    
    if (a->n_dims == 1) {
        fprintf(stderr, "Cannot perform a dot product with a scalar, use tensor_multiply...");
    } else if (a->n_dims > 2 || b -> n_dims > 2)  {
        fprintf(stderr, "Currently only support matrix dot products, todo..");
    }

    if (a->shape[a->n_dims - 1] != b->shape[0]) {
        fprintf(stderr, "Cannot perform a dot product, inner dims do not match...");
    }
    // todo, use BLAS in the long run but first implement naive solution for learning...
    
}


Tensor* tensor_negate(Tensor* tensor) {
    for (size_t i = 0; i < tensor->size; i++) {
        tensor->data[i] = -1.0f * tensor->data[i];
    }
    return tensor;
}


