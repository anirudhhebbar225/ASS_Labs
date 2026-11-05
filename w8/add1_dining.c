// Dining philosophers with a MONITOR (mutex + condition variables)
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
#define LEFT  (i + N - 1) % N
#define RIGHT (i + 1) % N
enum { THINKING, HUNGRY, EATING } state[N];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;   // monitor lock
pthread_cond_t self[N];
void test(int i) {                               // can i eat? both neighbours not eating
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&self[i]);
    }
}
void pickup(int i) {
    pthread_mutex_lock(&m);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING) pthread_cond_wait(&self[i], &m);
    pthread_mutex_unlock(&m);
}
void putdown(int i) {
    pthread_mutex_lock(&m);
    state[i] = THINKING;
    test(LEFT);                                  // let neighbours eat
    test(RIGHT);
    pthread_mutex_unlock(&m);
}
void *philosopher(void *arg) {
    int i = *(int *)arg;
    for (int k = 0; k < 2; k++) {
        printf("Philosopher %d thinking\n", i);
        sleep(1);
        pickup(i);
        printf("Philosopher %d EATING\n", i);
        sleep(1);
        putdown(i);
    }
    return NULL;
}
int main() {
    pthread_t t[N]; int id[N];
    for (int i = 0; i < N; i++) pthread_cond_init(&self[i], NULL);
    for (int i = 0; i < N; i++) { id[i] = i; pthread_create(&t[i], NULL, philosopher, &id[i]); }
    for (int i = 0; i < N; i++) pthread_join(t[i], NULL);
    return 0;
}
