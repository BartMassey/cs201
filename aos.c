#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

struct tile {
    uint64_t lines[8];
};

void init_tiles_slow(uint64_t ntiles, struct tile *tiles) {
    for (int i = 0; i < 8; i++)
        for (uint64_t j = 0; j < ntiles; j++)
            tiles[j].lines[i] = i + j;
}

uint64_t sum_tiles_slow(uint64_t ntiles, struct tile *tiles) {
    uint64_t tilesum = 0;
    for (int i = 0; i < 8; i++)
        for (uint64_t j = 0; j < ntiles; j++)
            tilesum += tiles[j].lines[i];
    return tilesum;
}

uint64_t init_sum_tiles_fast(uint64_t ntiles, struct tile *tiles) {
    uint64_t tilesum = 0;
    for (uint64_t j = 0; j < ntiles; j++) {
        for (int i = 0; i < 8; i++) {
            tiles[j].lines[i] = i + j;
            tilesum += i + j;
        }
    }
    return tilesum;
}

int main(int argc, char **argv) {
    assert(argc == 3);
    uint64_t n = atol(argv[2]);
    assert(n > 0);
    struct tile *tiles = malloc(n * sizeof *tiles);
    assert(tiles);
    uint64_t tilesum;
    switch(argv[1][0]) {
    case '-':
        init_tiles_slow(n, tiles);
        tilesum = sum_tiles_slow(n, tiles);
        break;
    case '+':
        tilesum = init_sum_tiles_fast(n, tiles);
        break;
    default:
        assert(0);
    }
    printf("%lu\n", tilesum);
    return 0;
}
