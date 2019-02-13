#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern int64_t asmfn(int64_t, int64_t);

int main(int argc, char **argv) {
    assert(argc == 3);
    int64_t a1 = atoi(argv[1]);
    int64_t a2 = atoi(argv[2]);
    int64_t r = asmfn(a1, a2);
    printf("%ld\n", r);
    return 0;
}
