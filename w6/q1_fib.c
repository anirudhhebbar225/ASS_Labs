// Usage: ./a.out 10        compile: gcc q1_fib.c -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int fib[100], n;                          // shared data
void *gen_fib(void *arg) {
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i < n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    return NULL;
}
int main(int argc, char *argv[]) {
    n = atoi(argv[1]);
    pthread_t t;
    pthread_create(&t, NULL, gen_fib, NULL);
    pthread_join(t, NULL);                // wait for child thread
    for (int i = 0; i < n; i++) printf("%d ", fib[i]);
    printf("\n");
    return 0;
}
