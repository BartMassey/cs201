#include <stdio.h>

int main(int argc, char **argv) {
    FILE *f = fopen(argv[1], "r");
    while (1) {
        int ch = fgetc(f);
        if (ch == EOF)
            break;
        putchar(ch);
    }
    return 0;
}
