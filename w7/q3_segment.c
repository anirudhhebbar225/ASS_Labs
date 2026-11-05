#include <stdio.h>
struct seg { int base, limit; };
// From the figure: segment -> base (start), limit (end - start)
struct seg table[5] = {
    {1400, 1000},   // seg 0 : 1400 - 2400
    {6300,  400},   // seg 1 : 6300 - 6700
    {4300,  400},   // seg 2 : 4300 - 4700
    {3200, 1100},   // seg 3 : 3200 - 4300
    {4700, 1000}    // seg 4 : 4700 - 5700
};
int physical(int s, int offset) {
    if (offset >= table[s].limit) return -1;          // trap: addressing error
    return table[s].base + offset;
}
void show(int s, int off) {
    int pa = physical(s, off);
    if (pa == -1) printf("Segment %d, byte %d -> TRAP (offset >= limit %d)\n", s, off, table[s].limit);
    else          printf("Segment %d, byte %d -> physical address %d\n", s, off, pa);
}
int main() {
    printf("Seg  Base  Limit\n");
    for (int i = 0; i < 5; i++) printf("%d    %d  %d\n", i, table[i].base, table[i].limit);
    show(2, 53);     // 4353
    show(3, 852);    // 4052
    show(0, 1222);   // trap
    return 0;
}
