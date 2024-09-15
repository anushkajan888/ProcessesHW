#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        _exit(0);
    } else {
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}

