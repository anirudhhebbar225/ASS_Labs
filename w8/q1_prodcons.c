// Producer can be at most 10 items ahead of consumer -> buffer of 10 (empty starts at 10)
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define SIZE 10
int buf[SIZE], in = 0, out = 0;
sem_t mutex, full, empty;
void *producer(void *arg) {
    for (int i = 1; i <= 20; i++) {
        sem_wait(&empty);                  // blocks once 10 items are unconsumed
        sem_wait(&mutex);
        buf[in] = i; in = (in + 1) % SIZE;
        printf("Produced %d\n", i);
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}
void *consumer(void *arg) {
    for (int i = 1; i <= 20; i++) {
        sem_wait(&full);                   // wait for an item
        sem_wait(&mutex);
        int item = buf[out]; out = (out + 1) % SIZE;
        printf("        Consumed %d\n", item);
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);                          // slow consumer -> producer gets 10 ahead and waits
    }
    return NULL;
}
int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, SIZE);
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
