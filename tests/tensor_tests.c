// todo: use a real testing library...
#include "tensor.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void test_tensor_from_array() {
    printf("### test_tensor_from_array\n");

    // Create a tensor
    // Example: 2x3 tensor
    Tensor* tensor = tensor_from_array(2, (size_t[]){2, 3}, (float[]){1.0f, 2.0f, 3.0f, 4.0f});
    // Test setting and getting values
    if (tensor) {
        // Assert and check values
        assert(tensor->data[0] == 1.0f);
        assert(tensor->data[1] == 2.0f);
        assert(tensor->data[2] == 3.0f);
        assert(tensor->data[3] == 4.0f);
        tensor_print(tensor);
    } else {
        printf("#### FAIL: Failed to create tensor.\n\n");
        assert(false); // i really need to use a testing lib
    }

    // Free tensor
    tensor_free(tensor);

    printf("#### SUCCESS\n\n");
    
}

void test_scalar_tensor() {
    // Create a scalar
    printf("### test_scalar_tensor");
    Tensor* tensor = tensor_from_array(1, (size_t[]){1}, (float[]){20.0f});
    if (tensor) {
        tensor_print(tensor);
        assert(tensor->data[0] == 20.0f);
    } else {
        printf("#### FAIL: Failed to create tensor.\n\n");
        assert(false); // i really need to use a testing lib
    }
    printf("#### SUCCESS\n\n");
}

int main() {
    test_tensor_from_array();
    test_scalar_tensor();
}
