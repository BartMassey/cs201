/* Demonstrate roundoff in floating point. */

#include <stdio.h>

int main() {
    float f = 1.0;
    for (int r = 0; r < 100; r++)
        f += 1e-30;
    printf("%g\n", f - 1.0);
    return 0;
}
