/*
 * XXX Example showing that array indices are syntactic
 * sugar.
 */

#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t a[2];
    a[0] = 1;
    *(a + 1) = 2;
    /* prints 2 2 2 2 */
    printf("%u %u %u %u\n", *(a + 1), a[1], *(1 + a), 1[a]);
    return 0;
}
