#include <stdio.h>

int main() {
    int n;
    int at[10], bt[10], priority[10], wt[10], tat[10], ct[10];
    float totaltat = 0, totalwt = 0;

    // Input number of processes
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    // Input arrival time, burst time, and priority for each process
    printf("\nEnter the Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process[%d]\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    // Initialize completion time, waiting time, and turnaround time
    for (int i = 0; i < n; i++) {
        ct[i] = 0;
        wt[i] = 0;
        tat[i] = 0;
    }

    int current_time = 0;
    int completed = 0;

    // Priority Scheduling Logic
    while (completed != n) {
        int highest_priority = -1;
        int selected_process = -1;

        // Find the process with the highest priority that has arrived and not completed
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && ct[i] == 0) {
                if (highest_priority == -1 || priority[i] < highest_priority) {
                    highest_priority = priority[i];
                    selected_process = i;
                }
            }
        }

        if (selected_process == -1) {
            current_time++; // No process available, increment time
        } else {
            // Execute the selected process
            ct[selected_process] = current_time + bt[selected_process];
            tat[selected_process] = ct[selected_process] - at[selected_process];
            wt[selected_process] = tat[selected_process] - bt[selected_process];

            // Update totals
            totaltat += tat[selected_process];
            totalwt += wt[selected_process];

            current_time = ct[selected_process]; // Move time forward
            completed++; // One more process completed
        }
    }

    // Display results
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", i + 1, at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    // Calculate and display averages
    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}