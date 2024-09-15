#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();
    if (pid1 == 0) {
        _exit(1);
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            _exit(2);
        } else {
            int status;
            waitpid(pid1, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child 1 exited with status %d\n", WEXITSTATUS(status));
            }

            waitpid(pid2, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child 2 exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}

