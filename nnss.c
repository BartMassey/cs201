#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "strtoi32.h"

/*
 * Return the sum of squares of all the non-negative
 * integers in the given array, or -1 if there were none.
 */
int64_t sum_squares_nonneg(int32_t *vals, size_t nvals) {
    int64_t sum = 0;
    int nn_found = 0;
    for (int i = 0; i < nvals; i++) {
        int64_t v = vals[i];
        if (v < 0)
            continue;
        nn_found = 1;
        sum += v * v;
    }
    if (!nn_found)
        return -1;
    return sum;
}


int main(int argc, char **argv) {
    argv += 1;
    int nvals = argc - 1;
    assert(nvals >= 0);
    int32_t *vals = malloc(nvals * sizeof *vals);
    if (!vals) {
        perror("nnss: malloc");
        return -1;
    }

    for (int i = 0; i < nvals; i++) {
        int result = strtoi32(argv[i], &vals[i]);
        if (result == -1) {
            perror("nnss");
            return 1;
        }
    }

    int64_t result = sum_squares_nonneg(vals, nvals);
    if (result == -1) {
        fprintf(stderr, "nnns: no positive numbers\n");
        return 1;
    }
    printf("%ld\n", result);

    free(vals);
    return 0;
}
