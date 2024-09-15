#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        _exit(0);
    } else {
        sleep(10);
        // The parent does not call wait(), so the child becomes a zombie.
    }

    return 0;
}

