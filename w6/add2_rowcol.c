// One thread for row sums, one for column sums
#include <stdio.h>
#include <pthread.h>
int a[10][10], r, c;
void *rowsum(void *arg) {
    for (int i = 0; i < r; i++) { int s = 0; for (int j = 0; j < c; j++) s += a[i][j]; printf("Row %d sum = %d\n", i, s); }
    return NULL;
}
void *colsum(void *arg) {
    for (int j = 0; j < c; j++) { int s = 0; for (int i = 0; i < r; i++) s += a[i][j]; printf("Col %d sum = %d\n", j, s); }
    return NULL;
}
int main() {
    printf("Enter rows cols: ");
    scanf("%d %d", &r, &c);
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, rowsum, NULL);
    pthread_join(t1, NULL);               // join first so output isn't mixed
    pthread_create(&t2, NULL, colsum, NULL);
    pthread_join(t2, NULL);
    return 0;
}
