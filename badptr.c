/*
 * XXX Example of undefined memory reference 
 * because pointer arithmetic.
 */

#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t x  = 0x01020304;
    /* prints 1 (little-endian) */
    printf("%d\n", * (uint8_t *) &x); 
    /* prints whatever byte is in memory after x */
    printf("%d\n", * (uint8_t *) (&x + 1)); 
    return 0;
}
