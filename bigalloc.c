#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define BLOCKSIZE (100*1024*1024)

int main() {
    uint64_t x = 0;
    uint64_t *p = 0;
    while (1) {
        uint64_t *np = malloc(BLOCKSIZE * sizeof *p);
        if (!np)
            break;
        x ^= (uint64_t) np;
        for (int i = 0; i < BLOCKSIZE; i++)
            np[i] = x;
        p = np;
    }
    printf("%lx %lx\n", x, p);
    return 0;
}
