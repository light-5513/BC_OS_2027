#include <stdio.h>

int main() {
    int n, quantum;
    int at[10], bt[10], rem_bt[10], wt[10], tat[10], ct[10];
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
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int t = 0; // Current time
    int done; // Flag to check if all processes are done

    while (1) {
        done = 1; // Assume all processes are done

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) { // If process has remaining burst time and has arrived
                done = 0; // There is still a pending process

                if (rem_bt[i] > quantum) {
                    t += quantum; // Execute for time quantum
                    rem_bt[i] -= quantum; // Reduce remaining burst time
                } else {
                    t += rem_bt[i]; // Execute for remaining time
                    ct[i] = t; // Completion time
                    wt[i] = ct[i] - at[i] - bt[i]; // Waiting time
                    rem_bt[i] = 0; // Process is done
                }
            }
        }
        if (done == 1) // If all processes are completed, break
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst time + Waiting time
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
