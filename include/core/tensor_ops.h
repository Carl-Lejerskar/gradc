#ifndef TENSOR_OPS
#define TENSOR_OPS

#include "tensor.h"

Tensor* tensor_add(const Tensor* a, const Tensor* b);
Tensor* tensor_subtract(const Tensor* a, const Tensor* b);
Tensor* tensor_multipy(const Tensor* a, const Tensor* b);
Tensor* tensor_dot(const Tensor* a, const Tensor* b);

#endif
