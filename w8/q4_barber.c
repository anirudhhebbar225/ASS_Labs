// Sleeping barber: 1 barber, 3 waiting chairs, 8 customers
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define CHAIRS 3
sem_t customers, barber, mutex;
int waiting = 0;
void *barberFn(void *arg) {
    while (1) {
        sem_wait(&customers);              // sleep until a customer arrives
        sem_wait(&mutex);
        waiting--;
        sem_post(&barber);                 // call customer to the chair
        sem_post(&mutex);
        printf("Barber cutting hair (waiting: %d)\n", waiting);
        sleep(2);
    }
}
void *customerFn(void *arg) {
    int id = *(int *)arg;
    sem_wait(&mutex);
    if (waiting < CHAIRS) {
        waiting++;
        printf("Customer %d sits (waiting: %d)\n", id, waiting);
        sem_post(&customers);              // wake barber
        sem_post(&mutex);
        sem_wait(&barber);                 // wait for barber
        printf("Customer %d getting haircut\n", id);
    } else {
        sem_post(&mutex);
        printf("Customer %d leaves (no chair)\n", id);
    }
    return NULL;
}
int main() {
    sem_init(&customers, 0, 0);
    sem_init(&barber, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_t b, c[8];
    int id[8];
    pthread_create(&b, NULL, barberFn, NULL);
    for (int i = 0; i < 8; i++) {
        id[i] = i + 1;
        pthread_create(&c[i], NULL, customerFn, &id[i]);
        sleep(1);                          // customers arrive every second
    }
    for (int i = 0; i < 8; i++) pthread_join(c[i], NULL);
    sleep(2);
    return 0;
}
