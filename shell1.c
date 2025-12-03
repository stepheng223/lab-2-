#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_alarm = 0;

void handler(int sig) {
    printf("Hello World!\n");
    got_alarm = 1;
}

int main() {
    signal(SIGALRM, handler);
    alarm(5);

    while (!got_alarm) {
        pause();
    }

    printf("Turing was right!\n");
    return 0;
}
