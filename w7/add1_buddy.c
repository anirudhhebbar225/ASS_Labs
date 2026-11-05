// Buddy system: sizes are powers of 2. Split big blocks in half; on free, merge with buddy.
#include <stdio.h>
#define MAX 1024
int freeList[11][64], cnt[11];      // freeList[k] = start addresses of free blocks of size 2^k
int order(int size) { int k = 0; while ((1 << k) < size) k++; return k; }
int alloc(int size) {
    int k = order(size), j = k;
    while (j <= 10 && cnt[j] == 0) j++;            // find smallest free block >= 2^k
    if (j > 10) return -1;
    int addr = freeList[j][--cnt[j]];
    while (j > k) {                                // split until right size
        j--;
        freeList[j][cnt[j]++] = addr + (1 << j);   // right half stays free
    }
    printf("Alloc %4d -> block of %4d at %4d\n", size, 1 << k, addr);
    return addr;
}
void release(int addr, int size) {
    int k = order(size), orig = addr;
    while (k < 10) {
        int buddy = addr ^ (1 << k), found = -1;   // buddy address = addr XOR size
        for (int i = 0; i < cnt[k]; i++) if (freeList[k][i] == buddy) found = i;
        if (found == -1) break;                    // buddy busy -> stop merging
        freeList[k][found] = freeList[k][--cnt[k]];
        if (buddy < addr) addr = buddy;
        k++;                                       // merged block is twice as big
    }
    freeList[k][cnt[k]++] = addr;
    printf("Free  at %4d -> free block of %4d at %4d\n", orig, 1 << k, addr);
}
int main() {
    freeList[10][cnt[10]++] = 0;                   // one free block of 1024
    int a = alloc(100), b = alloc(240), c = alloc(60);
    release(a, 100); release(c, 60); release(b, 240);
    return 0;
}
