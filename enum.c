#include <stdio.h>

enum state {
    STATE_INITIAL,
    STATE_PLAYING = 17,
    STATE_PAUSED,
};

int main() {
    enum state s = STATE_INITIAL;
    /* ... game code */
    if (s == STATE_PLAYING) {
        s = STATE_PAUSED;
    }
    printf("%d\n", STATE_PAUSED);
    return 0;
}
