#include <stdio.h>

int main() {
    int n;
    int at[10], bt[10], wt[10], tat[10], ct[10];
    float totaltat = 0, totalwt = 0;

    // Input number of processes
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    printf("\nEnter the Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process[%d]\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Initialize completion time, waiting time, and turnaround time
    ct[0] = at[0] + bt[0]; // Completion time of the first process
    tat[0] = ct[0] - at[0]; // Turnaround time of the first process
    wt[0] = tat[0] - bt[0]; // Waiting time of the first process

    // Calculate completion time, waiting time, and turnaround time for the rest of the processes
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1]) {
            ct[i] = at[i] + bt[i]; // If the process arrives after the previous process completes
        } else {
            ct[i] = ct[i - 1] + bt[i]; // If the process arrives before the previous process completes
        }
        tat[i] = ct[i] - at[i]; // Turnaround time = Completion time - Arrival time
        wt[i] = tat[i] - bt[i]; // Waiting time = Turnaround time - Burst time
    }

    // Calculate total turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        totaltat += tat[i];
        totalwt += wt[i];
    }

    // Display results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Calculate and display averages
    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}