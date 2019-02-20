#include <assert.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

uint32_t counter = 0;

void handle_sigio(int signum) {
    char buf[2];
    assert(signum == SIGIO);
    int n = read(0, buf, 2);
    if (n == -1)
        return;
    assert(n == 2);
    assert(buf[1] == '\n');
    assert(isdigit(buf[0]));
    counter += buf[0] - '0';
}

void install_handler(void) {
    sigset_t sigs;
    sigemptyset(&sigs);
    struct sigaction act;
    act.sa_handler = handle_sigio;
    act.sa_mask = sigs;
    act.sa_flags = 0;
    assert(sigaction(SIGIO, &act, 0) != -1);
    int pid = getpid();
    assert(pid != -1);
    assert(fcntl(0, F_SETOWN, pid) != -1);
    assert(fcntl(0, F_SETFL, O_ASYNC | O_NONBLOCK) != -1);
}

int main() {
    install_handler();
    volatile uint32_t last_read = 0;
    while (1) {
        printf(".\n");
        sleep(1);
        if (last_read != counter) {
            printf("%d\n", counter);
            last_read = counter;
        }
    }
}
