// First readers-writers: readers have priority
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex, wrt;          // mutex protects readcount, wrt = writer lock
int readcount = 0, data = 0;
void *reader(void *arg) {
    int id = *(int *)arg;
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) sem_wait(&wrt);    // first reader locks out writers
    sem_post(&mutex);

    printf("Reader %d reads data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0) sem_post(&wrt);    // last reader lets writers in
    sem_post(&mutex);
    return NULL;
}
void *writer(void *arg) {
    int id = *(int *)arg;
    sem_wait(&wrt);
    data++;
    printf("Writer %d writes data = %d\n", id, data);
    sleep(1);
    sem_post(&wrt);
    return NULL;
}
int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
    pthread_t r[3], w[2];
    int id[3] = {1, 2, 3};
    for (int i = 0; i < 2; i++) pthread_create(&w[i], NULL, writer, &id[i]);
    for (int i = 0; i < 3; i++) pthread_create(&r[i], NULL, reader, &id[i]);
    for (int i = 0; i < 2; i++) pthread_join(w[i], NULL);
    for (int i = 0; i < 3; i++) pthread_join(r[i], NULL);
    return 0;
}
