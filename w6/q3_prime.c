#include <stdio.h>
#include <pthread.h>
int start, end;
void *primes(void *arg) {
    for (int n = start; n <= end; n++) {
        if (n < 2) continue;
        int isPrime = 1;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) { isPrime = 0; break; }
        if (isPrime) printf("%d ", n);
    }
    printf("\n");
    return NULL;
}
int main() {
    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);
    pthread_t t;
    pthread_create(&t, NULL, primes, NULL);
    pthread_join(t, NULL);
    return 0;
}
