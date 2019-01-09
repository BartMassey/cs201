#include <stdint.h>
#include <stdio.h>

int main() {
    uint16_t x = 0x0102;
    printf("0x%02x\n", (uint8_t) x);
    return 0;
}
