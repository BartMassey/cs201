/* Filter integers from the input according to filter rules. */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t read_arg(char *arg) {
    char *endptr = arg;
    int64_t value = strtoll(arg, &endptr, 0);
    if (*endptr != '\0') {
        fprintf(stderr, "bittool: invalid char in number %s\n", arg);
        exit(-1);
    }
    if (value < 0 || value >= UINT32_MAX) {
        fprintf(stderr, "bittool: number %s out of range\n", arg);
        exit(-1);
    }
    return (uint32_t) value;
}

void show_bits(char *a1, char *a2) {
    /* Insert your code for the two arguments case here. */
}

void set_bits(int na, char **a) {
    /* Insert your code for the three-plus arguments case here. */
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "bittool: usage: bittool <n> <n> [<n> ...]\n");
        return -1;
    }
    if (argc == 3) {
        show_bits(argv[1], argv[2]);
        return 0;
    }
    set_bits(argc - 1, argv + 1);
    return 0;
}
