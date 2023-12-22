// todo: use a real testing library...
#include <stdio.h>
#include <assert.h>
#include "utils.h"
#include "tensor.h"
#include "tensor_ops.h"

void test_tensor_add() {
    printf("### test_tensor_add\n");

    // Create a tensor
    // Example: 2x3 tensor
    Tensor* a = tensor_from_array(2, (size_t[]){2,2}, (float[]){1.0f, 2.0f, 3.0f, 4.0f});
    Tensor* b = tensor_from_array(2, (size_t[]){2,2}, (float[]){1.0f, 2.0f, 3.0f, 4.0f});
    Tensor* c = tensor_add(a, b);

    printf("a:\n");
    tensor_print(a);
    printf("b:\n");
    tensor_print(b);
    printf("a+b:\n");
    tensor_print(c);

    assert(array_equals(c->data, (float[]){2.0f, 4.0f, 6.0f, 8.0f}, c->size));
    // Free tensors
    tensor_free(a);
    tensor_free(b);
    tensor_free(c);

    printf("#### SUCCESS\n\n");
}

int main() {
    test_tensor_add();
}
