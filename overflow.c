#include <stdint.h>
#include <stdio.h>

int main() {
    // x should be 0x11e, but that won't fit.
    uint8_t x = 0x8f + 0x8f;
    printf("%x\n", x);
    // ???
    int8_t y = -143 + -143;
    printf("%x\n", y);
    return 0;
}
