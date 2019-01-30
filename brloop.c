/* Print characters until an 'x' is encountered or end of file. */

#include <stdio.h>

int main() {
    while (1) {
        int ch = getchar();
        if (ch == -1)
            break;
        if (ch == 'x')
            break;
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
