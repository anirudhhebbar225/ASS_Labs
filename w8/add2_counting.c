// Counting semaphore = 3 -> at most 3 threads inside at once
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t s;
void *worker(void *arg) {
    int id = *(int *)arg, v;
    sem_wait(&s);
    sem_getvalue(&s, &v);
    printf("Thread %d entered (slots left: %d)\n", id, v);
    sleep(1);
    printf("Thread %d leaving\n", id);
    sem_post(&s);
    return NULL;
}
int main() {
    sem_init(&s, 0, 3);
    pthread_t t[6]; int id[6];
    for (int i = 0; i < 6; i++) { id[i] = i + 1; pthread_create(&t[i], NULL, worker, &id[i]); }
    for (int i = 0; i < 6; i++) pthread_join(t[i], NULL);
    return 0;
}
