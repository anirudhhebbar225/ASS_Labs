// First / Best / Worst / Next fit (array version - easiest to remember)
#include <stdio.h>
int nb, np, block[20], proc[20];
void allocate(char *name, int type) {
    int b[20], alloc[20], last = 0;
    for (int i = 0; i < nb; i++) b[i] = block[i];          // fresh copy of block sizes
    for (int p = 0; p < np; p++) {
        int pick = -1;
        if (type == 3) {                                    // NEXT fit: first fit, but start from last position
            for (int k = 0; k < nb; k++) {
                int i = (last + k) % nb;
                if (b[i] >= proc[p]) { pick = i; last = i; break; }
            }
        } else {
            for (int i = 0; i < nb; i++) {
                if (b[i] < proc[p]) continue;               // too small
                if (pick == -1) { pick = i; if (type == 0) break; }   // FIRST fit: take first one
                else if (type == 1 && b[i] < b[pick]) pick = i;       // BEST fit: smallest that fits
                else if (type == 2 && b[i] > b[pick]) pick = i;       // WORST fit: largest
            }
        }
        alloc[p] = pick;
        if (pick != -1) b[pick] -= proc[p];                 // remaining hole
    }
    printf("\n%s\nProcess  Size  Block\n", name);
    for (int p = 0; p < np; p++)
        if (alloc[p] == -1) printf("P%d       %-5d Not allocated\n", p + 1, proc[p]);
        else                printf("P%d       %-5d B%d\n", p + 1, proc[p], alloc[p] + 1);
}
int main() {
    printf("Number of blocks: ");    scanf("%d", &nb);
    printf("Block sizes: ");          for (int i = 0; i < nb; i++) scanf("%d", &block[i]);
    printf("Number of processes: "); scanf("%d", &np);
    printf("Process sizes: ");        for (int i = 0; i < np; i++) scanf("%d", &proc[i]);
    allocate("FIRST FIT", 0);
    allocate("BEST FIT", 1);
    allocate("WORST FIT", 2);
    allocate("NEXT FIT", 3);
    return 0;
}
