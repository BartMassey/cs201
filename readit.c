#include <errno.h>
#include <stdio.h>

int main(int argc, char **argv) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("open");
        return 1;
    }
    while (1) {
        errno = 0;
        int ch = fgetc(f);
        if (ch == EOF)
            break;
        putchar(ch);
    }
    if (errno != 0) {
        perror("fgetc");
        return 1;
    }
    return 0;
}
