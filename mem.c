/* Example showing various kinds of memory. */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Allocated and initialized at program startup. */
uint32_t a = 5;

/* Allocated and set to 0 at program startup. */
uint32_t b;

uint32_t f(uint32_t *cp) {
    /*
     * Allocated on entry to f().
     * Disappears when f() returns.
     */
    uint32_t d = a + b + *cp;
    /* Pointer is local. String is allocated in read-only
     * memory at program startup.
     */
    char *s = "3";
    return d + s[0] - '0';
}

int main() {
    /* Allocated on heap by malloc(), not initialized. */
    uint32_t *cp  = (uint32_t *) malloc(sizeof *cp);
    *cp = 8;
    /* Prints a + b + *cp + 3 == 16. */
    printf("%d\n", f(cp)); 
    return 0;
}
