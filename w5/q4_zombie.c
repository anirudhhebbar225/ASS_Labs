// Run:  ./a.out &   then:  ps -el | grep defunct   (Z = zombie)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child %d exiting\n", getpid());
        exit(0);                          // child dies ...
    } else {
        sleep(30);                        // ... parent never calls wait -> zombie
        printf("Parent exiting, init adopts and cleans zombie\n");
    }
    return 0;
}
