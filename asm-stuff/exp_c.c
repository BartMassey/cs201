#include <stdint.h>

int64_t asmfn(int32_t b, int32_t x) {
    uint64_t result = 1;
    while (x != 0) {
	result *= b;
	x--;
    }
    return result;
}
