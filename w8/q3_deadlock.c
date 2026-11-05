// Deadlock: T1 takes A then B, T2 takes B then A -> each waits for the other forever
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t A, B;
void *t1(void *arg) {
    sem_wait(&A); printf("T1 got A, waiting for B...\n");
    sleep(1);
    sem_wait(&B); printf("T1 got B\n");      // never reached
    sem_post(&B); sem_post(&A);
    return NULL;
}
void *t2(void *arg) {
    sem_wait(&B); printf("T2 got B, waiting for A...\n");
    sleep(1);
    sem_wait(&A); printf("T2 got A\n");      // never reached
    sem_post(&A); sem_post(&B);
    return NULL;
}
int main() {
    sem_init(&A, 0, 1);
    sem_init(&B, 0, 1);
    pthread_t x, y;
    pthread_create(&x, NULL, t1, NULL);
    pthread_create(&y, NULL, t2, NULL);
    pthread_join(x, NULL);                   // hangs: DEADLOCK (Ctrl+C to stop)
    pthread_join(y, NULL);
    printf("Finished (no deadlock)\n");
    return 0;
}
