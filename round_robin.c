#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int quantum) {
    int rem_bt[20];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i]; // remaining burst times

    int time = 0; // current time

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // there is a process left

                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        // if all processes are done
        if (done == 1)
            break;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void display(int n, int bt[], int wt[], int tat[]) {
    int total_wt = 0, total_tat = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n, bt[20], wt[20], tat[20], quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findWaitingTime(n, bt, wt, quantum);
    findTurnAroundTime(n, bt, wt, tat);
    display(n, bt, wt, tat);

    return 0;
}
