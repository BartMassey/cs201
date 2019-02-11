#include <stdint.h>

uint64_t asmfn(uint32_t b, uint32_t x) {
    uint64_t result = 1;
    while (x != 0) {
	result *= b;
	x--;
    }
    return result;
}
