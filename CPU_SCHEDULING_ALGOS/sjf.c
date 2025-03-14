#include <stdio.h>

int main() {
    int n;
    int bt[10], wt[10], tat[10], ct[10];
    float totaltat = 0, totalwt = 0;

    // Input number of processes
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    printf("\nEnter the Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort processes based on burst time (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    // Calculate completion time, waiting time, and turnaround time
    ct[0] = bt[0]; // Completion time of the first process
    tat[0] = ct[0]; // Turnaround time of the first process
    wt[0] = 0;      // Waiting time of the first process

    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i]; // Completion time = Previous completion time + Burst time
        tat[i] = ct[i];            // Turnaround time = Completion time (since arrival time is 0)
        wt[i] = tat[i] - bt[i];    // Waiting time = Turnaround time - Burst time
    }

    // Calculate total turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        totaltat += tat[i];
        totalwt += wt[i];
    }

    // Display results
    printf("\nProcess\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], ct[i], tat[i], wt[i]);
    }

    // Calculate and display averages
    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}