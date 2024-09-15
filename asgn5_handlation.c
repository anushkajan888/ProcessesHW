#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        _exit(0);
    } else {
        wait(NULL);
        // The parent now calls wait() to prevent the child from becoming a zombie.
    }

    return 0;
}

