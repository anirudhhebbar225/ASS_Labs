#include <stdio.h>
#include <pthread.h>
int a[100], n, evenSum = 0, oddSum = 0;
void *even(void *arg) { for (int i = 0; i < n; i++) if (a[i] % 2 == 0) evenSum += a[i]; return NULL; }
void *odd(void *arg)  { for (int i = 0; i < n; i++) if (a[i] % 2 != 0) oddSum  += a[i]; return NULL; }
int main() {
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, even, NULL);
    pthread_create(&t2, NULL, odd, NULL);
    pthread_join(t1, NULL);               // parent waits for both
    pthread_join(t2, NULL);
    printf("Even sum = %d\nOdd sum = %d\n", evenSum, oddSum);
    return 0;
}
