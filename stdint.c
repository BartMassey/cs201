#include <stdint.h>
#include <stdio.h>

int main() {
    int8_t c = 1;
    printf("int8: %lu bytes\n", sizeof c);
    uint8_t uc = 2;
    printf("uint8: %lu bytes\n", sizeof uc);
    int16_t s = 3;
    printf("int16: %lu bytes\n", sizeof s);
    int32_t i = 4;
    printf("int32: %lu bytes\n", sizeof i);
    int64_t l = 5;
    printf("int64: %lu bytes\n", sizeof l);
    return 0;
}
