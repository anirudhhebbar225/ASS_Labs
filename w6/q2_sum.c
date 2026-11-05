#include <stdio.h>
#include <pthread.h>
void *sum(void *arg) {
    int n = *(int *)arg;
    long s = 0;
    for (int i = 0; i <= n; i++) s += i;
    return (void *)s;                     // send result back to main
}
int main() {
    int n;
    long result;
    printf("Enter n: ");
    scanf("%d", &n);
    pthread_t t;
    pthread_create(&t, NULL, sum, &n);
    pthread_join(t, (void **)&result);    // receive result
    printf("Sum of 0..%d = %ld\n", n, result);
    return 0;
}
