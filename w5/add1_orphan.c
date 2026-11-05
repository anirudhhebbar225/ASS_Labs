#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child: parent PID before = %d\n", getppid());
        sleep(3);                         // parent dies meanwhile
        printf("Child: parent PID after  = %d (adopted)\n", getppid());
    } else {
        sleep(1);
        printf("Parent exiting\n");       // exits without waiting -> child is orphan
    }
    return 0;
}
