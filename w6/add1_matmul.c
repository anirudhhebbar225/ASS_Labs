// One thread per row of the result
#include <stdio.h>
#include <pthread.h>
int A[10][10], B[10][10], C[10][10], r1, c1, c2;
void *row(void *arg) {
    int i = *(int *)arg;
    for (int j = 0; j < c2; j++) {
        C[i][j] = 0;
        for (int k = 0; k < c1; k++) C[i][j] += A[i][k] * B[k][j];
    }
    return NULL;
}
int main() {
    printf("Enter rows1 cols1 cols2: ");
    scanf("%d %d %d", &r1, &c1, &c2);
    printf("Matrix A:\n"); for (int i = 0; i < r1; i++) for (int j = 0; j < c1; j++) scanf("%d", &A[i][j]);
    printf("Matrix B:\n"); for (int i = 0; i < c1; i++) for (int j = 0; j < c2; j++) scanf("%d", &B[i][j]);
    pthread_t t[10]; int id[10];
    for (int i = 0; i < r1; i++) { id[i] = i; pthread_create(&t[i], NULL, row, &id[i]); }
    for (int i = 0; i < r1; i++) pthread_join(t[i], NULL);
    printf("Result:\n");
    for (int i = 0; i < r1; i++) { for (int j = 0; j < c2; j++) printf("%d ", C[i][j]); printf("\n"); }
    return 0;
}
