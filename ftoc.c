#include <stdio.h>

int main() {
    int temp_fahrenheit = 72;
    int temp_celsius = temp_fahrenheit * 5 / 9 + 32;
    printf("%dF = %dC\n", temp_fahrenheit, temp_celsius);
    return 0;
}
