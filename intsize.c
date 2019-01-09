#include <stdio.h>

int main() {
    char c = 1;
    printf("char: %lu bytes\n", sizeof c);
    unsigned char uc = 2;
    printf("unsigned char: %lu bytes\n", sizeof uc);
    short s = 3;
    printf("short: %lu bytes\n", sizeof s);
    int i = 4;
    printf("int: %lu bytes\n", sizeof i);
    long l = 5;
    printf("long: %lu bytes\n", sizeof l);
    long long ll = 6;
    printf("long long: %lu bytes\n", sizeof ll);
    return 0;
}
