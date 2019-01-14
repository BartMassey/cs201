/* Generate a centralized random walk with occasional spikes. */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    /* Current value in walk. */
    int32_t v = 0;
    int n = atoi(argv[1]);
    srand(getpid());

    for (int i = 0; i < n; i++) {
        /* Maybe spike. */
        if (rand() % 10 == 0) {
            printf("%d\n", rand() % 100 - 49);
            continue;
        }
        
        /* Otherwise walk. */
        v += rand() % 10 - 5 - v / 4;
        printf("%d\n", v);
    }
    return 0;
}
