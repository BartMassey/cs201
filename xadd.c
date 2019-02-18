#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    assert(argc == 3);
    int64_t x = atol(argv[1]);
    int64_t y = atol(argv[2]);
    asm("addq %1, %0" : "+rm" (x) : "rm" (y) : "cc");
    printf("(+ %d) %d\n", y, x);
    return 0;
}
