#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern uint64_t asmfn(uint64_t, uint64_t);

int main(int argc, char **argv) {
    assert(argc == 3);
    uint64_t a1 = atoi(argv[1]);
    uint64_t a2 = atoi(argv[2]);
    uint64_t r = asmfn(a1, a2);
    printf("%ld\n", r);
    return 0;
}
