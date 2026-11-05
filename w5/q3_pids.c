#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child : my PID=%d, parent PID=%d\n", getpid(), getppid());
    } else {
        printf("Parent: my PID=%d, parent PID=%d, child PID=%d\n", getpid(), getppid(), pid);
        wait(NULL);
    }
    return 0;
}
