#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1 PID: %d\n", getpid());
        _exit(0);
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            printf("Child 2 PID: %d\n", getpid());
            _exit(0);
        } else {
            int status;
            wait(&status);
            printf("Parent waited for a child to finish\n");

            waitpid(pid2, &status, 0);
            printf("Parent waited for specific child to finish\n");

            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}
