// MLFQ: Q1 = RR (q=4), Q2 = RR (q=8), Q3 = FCFS. All processes arrive at time 0.
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, time = 0;
    printf("Number of processes: ");
    scanf("%d", &n);
    int *burst = malloc(n * sizeof(int));     // malloc as asked
    int *rem   = malloc(n * sizeof(int));
    int *done  = malloc(n * sizeof(int));     // completion time
    printf("Burst times: ");
    for (int i = 0; i < n; i++) { scanf("%d", &burst[i]); rem[i] = burst[i]; }
    int quantum[3] = {4, 8, 1000000};         // Q3 FCFS = run till finish
    for (int q = 0; q < 3; q++) {
        printf("Queue %d: ", q + 1);
        for (int i = 0; i < n; i++) {
            if (rem[i] == 0) continue;
            int run = rem[i] < quantum[q] ? rem[i] : quantum[q];
            printf("P%d(%d-%d) ", i + 1, time, time + run);
            time += run;
            rem[i] -= run;                    // leftover drops to next queue
            if (rem[i] == 0) done[i] = time;
        }
        printf("\n");
    }
    float tw = 0, tt = 0;
    printf("\nP   Burst  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        int tat = done[i], wt = tat - burst[i];       // arrival = 0
        printf("P%d  %-5d  %-3d  %d\n", i + 1, burst[i], tat, wt);
        tt += tat; tw += wt;
    }
    printf("Avg TAT = %.2f, Avg WT = %.2f\n", tt / n, tw / n);
    free(burst); free(rem); free(done);
    return 0;
}
