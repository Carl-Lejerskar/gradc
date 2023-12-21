// todo: use a real testing library...
#include "tensor.h"
#include <stdio.h>
#include <assert.h>

void test_tensor_value_setting() {
    printf("Testing tensor value setting... yuh\n");

    // Create a tensor
    size_t shape[] = {2, 3};  // Example: 2x3 tensor
    Tensor* my_tensor = create_tensor(2, shape);
    // Test setting and getting values
    if (my_tensor) {
        // Set values in the tensor
        my_tensor->data[0] = 1.0f;
        my_tensor->data[1] = 2.0f;
        my_tensor->data[2] = 3.0f;
        my_tensor->data[3] = 4.0f;
        my_tensor->data[4] = 5.0f;
        my_tensor->data[5] = 6.0f;

        // Assert and check values
        assert(my_tensor->data[0] == 1.0f);
        assert(my_tensor->data[1] == 2.0f);
        assert(my_tensor->data[2] == 3.0f);
        assert(my_tensor->data[3] == 4.0f);
        assert(my_tensor->data[4] == 5.0f);
        assert(my_tensor->data[5] == 6.0f);

        print_tensor(my_tensor);
        printf("Value setting and getting test passed.\n");
    } else {
        printf("Failed to create tensor.\n");
    }

    // Free tensor
    free_tensor(my_tensor);

    // More tensor operations tests can be added here...

    printf("Tensor Operations Tests Completed.\n");
}

int main() {
    test_tensor_value_setting();
}
