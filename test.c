#include <stdio.h>
#include <string.h>
#include <stdint.h>

void function(int a, int b, int c) {
    char buffer1[5];
    char buffer2[20];

    //////////////////////////////////////////////////////////////////
    uintptr_t *frame_ptr;
    int distance = sizeof(buffer1) + sizeof(buffer2) + sizeof(int) * 3 + sizeof(uintptr_t);

    /**
     * @param __builtin_frame_address is the function of GCC
     * Get the current frame pointer
     * '0' means frame pointer
    */
    frame_ptr = (uintptr_t *)__builtin_frame_address(0);

    // Return address on the stack
    uintptr_t *ret_addr_ptr = frame_ptr + 1;

    // Skip the assignment x = 1;
    *ret_addr_ptr += 5;
    //////////////////////////////////////////////////////////////////
}

void main() {
    int x;
    x = 0;
    function(1, 2, 3);
    x = 1;
    printf("x=%d\n", x);
}
