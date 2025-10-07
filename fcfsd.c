#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek = 0, diff;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++) {
        diff = abs(req[i] - head);
        seek += diff;
        printf("Move from %d → %d, Seek = %d\n", head, req[i], diff);
        head = req[i];
    }

    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / n);

    return 0;
}
