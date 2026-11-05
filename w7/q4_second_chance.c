#include <stdio.h>
int main() {
    int n, f, pages[50], frame[10], ref[10], ptr = 0, faults = 0;
    printf("Number of pages: ");  scanf("%d", &n);
    printf("Reference string: "); for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    printf("Number of frames: "); scanf("%d", &f);
    for (int i = 0; i < f; i++) { frame[i] = -1; ref[i] = 0; }
    for (int i = 0; i < n; i++) {
        int hit = 0;
        for (int j = 0; j < f; j++)
            if (frame[j] == pages[i]) { ref[j] = 1; hit = 1; break; }   // hit -> give second chance
        if (!hit) {
            while (ref[ptr] == 1) {        // has a second chance? clear it, move on
                ref[ptr] = 0;
                ptr = (ptr + 1) % f;
            }
            frame[ptr] = pages[i];         // replace victim
            ref[ptr] = 0;
            ptr = (ptr + 1) % f;
            faults++;
        }
        printf("%2d : ", pages[i]);
        for (int j = 0; j < f; j++) frame[j] == -1 ? printf(" - ") : printf("%2d ", frame[j]);
        printf("%s\n", hit ? "Hit" : "Fault");
    }
    printf("Page faults = %d\nHit ratio = %.2f\n", faults, (float)(n - faults) / n);
    return 0;
}
