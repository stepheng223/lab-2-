#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void ParentProcess() {
    int i;
    for (i = 0; i < 20; i++) {
        printf("Parent Process: value of i = %d\n", i);
        sleep(1);
    }
}

void ChildProcess() {
    int i;
    for (i = 0; i < 20; i++) {
        printf("Child Process: value of i = %d\n", i);
        sleep(1);
    }
}

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        /* Child */
        ChildProcess();
    } else {
        /* Parent */
        ParentProcess();
    }

    return 0;
}
