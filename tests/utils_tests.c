// todo: use a real testing library...
#include "utils.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void test_array_equals() {
    printf("### test_array_equals\n");
    float a[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b[] = {1.0f, 2.0f, 3.0f, 4.0f};
    assert(array_equals(a, b, 4));
    float c[] = {0.0f, 1.0f, 2.0f, 3.0f};
    assert(!array_equals(a, c, 4));
    printf("#### SUCCESS\n\n");
}

int main() {
    test_array_equals();
}
