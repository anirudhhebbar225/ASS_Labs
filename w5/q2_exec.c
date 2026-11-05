// First compile Q1:  gcc q1_wait.c -o q1
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        execl("./q1", "q1", NULL);        // replace child with q1 program
        perror("exec failed");            // only runs if exec fails
    } else {
        wait(NULL);
        printf("Parent: exec'd child finished\n");
    }
    return 0;
}
