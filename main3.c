#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t cpid1, cpid2;
    int status;

    // Seed random using time + pid
    srandom(time(NULL) ^ getpid());

    // ---- FIRST CHILD ----
    cpid1 = fork();
    if (cpid1 < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    if (cpid1 == 0) {
        // Child 1
        int iterations = random() % 30; // up to 30 loops

        for (int i = 0; i < iterations; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());

            int nap = random() % 11; // sleep 0–10 seconds
            sleep(nap);

            printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",
                   getpid(), getppid());
        }

        exit(0);
    }

    // ---- SECOND CHILD ----
    cpid2 = fork();
    if (cpid2 < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    if (cpid2 == 0) {
        // Child 2
        int iterations = random() % 30;

        for (int i = 0; i < iterations; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());

            int nap = random() % 11;
            sleep(nap);

            printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",
                   getpid(), getppid());
        }

        exit(0);
    }

    // ---- PARENT PROCESS – waits for both children ----
    pid_t done;

    done = wait(&status);
    printf("Child Pid: %d has completed\n", done);

    done = wait(&status);
    printf("Child Pid: %d has completed\n", done);

    return 0;
}
