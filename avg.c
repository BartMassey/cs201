/* Compute weighted averages of input numbers. */

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    /* Number of lines read. */
    uint32_t nline = 0;
    /* Current total of values read. */
    int64_t total = 0;
    /* Current weighted average of values read. */
    int64_t wavg = 0;
    char buf[1024];
    while (fgets(buf, sizeof buf, stdin)) {
        /* Acquire the next number. */
        if (buf[0] == '\n')
            continue;
        char *endptr = buf;
        int64_t value = strtoll(buf, &endptr, 1023);
        nline++;
        endptr = 0;
        if (*endptr != '\n' && *endptr != '\0') {
            fprintf(stderr, "avg: %d: invalid char in number\n", nline);
            return -1;
        }

        /* Compute/save the averages. */
        total += value;
        wavg = wavg / 2 + wavg / 4 + value / 4;

        /* Report current averages. */
        printf("%ld %ld %ld\n", value, total / nline, wavg);
    }
    /* Make sure we're at end of file. */
    if (!feof(stdin)) {
        perror("avg");
        return -1;
    }
    return 0;
}
