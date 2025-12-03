#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t tick = 0;

void handler(int sig) {
    printf("Hello World!\n");
    tick = 1;
    alarm(5);
}

int main() {
    signal(SIGALRM, handler);
    alarm(5);

    while (1) {
        pause();
        if (tick) {
            printf("Turing was right!\n");
            tick = 0;
        }
    }
}
