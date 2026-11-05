#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child exiting with code 7\n");
        exit(7);
    } else {
        wait(&status);
        printf("Exit code of child = %d\n", status >> 8);   // leftmost byte (same as WEXITSTATUS)
    }
    return 0;
}
