/* Demonstrate roundoff in floating point. */

#include <stdio.h>

int main() {
    float f = 1.0;
    for (int r = 0; r < 90; r++)
        f *= 1.0 / 3.0;
    /* Should print 1.14574e-43. */
    printf("%g\n", f);
    return 0;
}
