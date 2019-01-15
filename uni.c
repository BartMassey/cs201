#include <assert.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {
    /* 0x1f60a == '😊' */
    wint_t smiley = L'😊';
    /* https://stackoverflow.com/a/41800614 */
    setlocale(LC_ALL, "C.UTF-8");
    int n = printf("%lu 0x%x %lc\n", sizeof smiley, smiley, smiley);
    assert(n >= 0);
    return 0;
}
