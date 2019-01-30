#include <stdio.h>

int g(int x) {
    return x + 1;
}

#ifdef USE_G
/* Compiler error; funcall in init */
int g0 = g(0);
#else
int g0 = 1;
#endif

int main() {
    printf("%d\n", g0);
    return 0;
}
