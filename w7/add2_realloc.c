#include <stdio.h>
#include <stdlib.h>
int main() {
    int *a = malloc(3 * sizeof(int));              // 3 ints
    for (int i = 0; i < 3; i++) a[i] = i + 1;
    a = realloc(a, 5 * sizeof(int));               // grow to 5 (old values kept)
    a[3] = 4; a[4] = 5;
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    a = realloc(a, 2 * sizeof(int));               // shrink to 2
    printf("%d %d\n", a[0], a[1]);
    free(a);                                       // release (realloc(a, 0) also frees)
    return 0;
}
