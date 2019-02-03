#include <stdint.h>
#include <stdio.h>

#ifdef USE_CONST
const int32_t BLOCKSIZE = 1024;
#else
#define BLOCKSIZE 1024
#endif

char block[BLOCKSIZE];

int main() {
    printf("%lu\n", sizeof block);
    return 0;
}
