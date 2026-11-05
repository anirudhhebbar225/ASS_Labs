#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child: running\n");
        sleep(2);
        printf("Child: done\n");
    } else {
        wait(NULL);                       // parent blocks here until child ends
        printf("Parent: child finished, parent continues\n");
    }
    return 0;
}
