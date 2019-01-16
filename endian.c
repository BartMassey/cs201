/* Determine processor endianness. */

#include <stdint.h>
#include <stdio.h>

int main() {
    uint32_t x = 0x05050505;
    uint32_t y = 0x04030201;
    for (int i = 0; i < sizeof y; i++)
        ((uint8_t *) &x)[i] = y >> (8 * i);
    switch (x) {
    case 0x01020304:
        printf("big-endian\n");
        return 0;
    case 0x04030201:
        printf("little-endian\n");
        return 0;
    default:
        printf("wat?\n");
        return 1;
    }
}
