#include <stdio.h>

char a[1L << 56];

int main() {
    printf("%d", a[(1L << 56) - 1]);
}
