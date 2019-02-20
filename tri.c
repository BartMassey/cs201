#include <assert.h>
#include <stdint.h>
#include <stdio.h>
extern int64_t atol(char *);

#define NTRI (1000 * 1000)

int64_t tri[NTRI];

int main(int argc, char **argv) {
    assert(argc == 2);
    uint64_t n = atol(argv[1]);
    for (int i = 1; i <= n; i++) {
        tri[i] = i;
        for (int j = 0; j < i; j++)
            tri[i] += j;
    }
    printf("%ld\n", tri[n]);
}
