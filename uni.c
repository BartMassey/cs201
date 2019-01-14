#include <assert.h>
#include <stdio.h>
#include <wchar.h>

int main() {
    // 0x1f60a == '😊'
    wint_t smiley = 0x1f60a;
    int n = wprintf("%lc\n", smiley);
    assert(n >= 0);
    return 0;
}
