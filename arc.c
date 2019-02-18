#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

inline static void
incref(int32_t *refp) {
    asm volatile("addl $1, (%0)" : : "r" (refp) : "memory");
}

inline static void
increfl(int32_t *refp) {
    asm volatile("lock addl $1, (%0)" : : "r" (refp) : "memory");
}

inline static int32_t
increfr(int32_t v) {
    asm volatile("addl $1, %0" : "=r" (v): :);
    return v;
}

int main(int argc, char **argv) {
    int32_t lock = 0;
    switch(argv[1][0]) {
    case 'u':
        for (uint32_t i = 0; i < 1000000000; i++)
            incref(&lock);
        break;
    case 'l':
        for (uint32_t i = 0; i < 1000000000; i++)
            increfl(&lock);
        break;
    case 'r':
        for (uint32_t i = 0; i < 1000000000; i++)
            lock = increfr(lock);
        break;
    default:
        abort();
    }
    printf("%u\n", lock);
    return 0;
}
