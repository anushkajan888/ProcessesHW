#include <stdio.h>
#include <stdlib.h>

void cleanup1() {
    printf("Cleanup function 1 called\n");
}

void cleanup2() {
    printf("Cleanup function 2 called\n");
}

int main() {
    atexit(cleanup1);
    atexit(cleanup2);

    printf("Main function execution\n");
    exit(0);

    return 0;
}

