#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    int i;

    pid = fork();

    if (pid < 0) {
        write(1, "Fork failed\n", 12);
        exit(1);
    }

    /* Both parent and child execute this loop */
    for (i = 0; i < 20; i++) {
        char buffer[100];
        int n = snprintf(buffer, sizeof(buffer),
                         "This line is from pid %d, value %d\n",
                         getpid(), i);
        write(1, buffer, n);
    }

    return 0;
}
