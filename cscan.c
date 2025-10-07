#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, seek = 0, i, j;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    // Add 0 and max value
    req[n] = 0;
    req[n + 1] = size - 1;
    n += 2;

    // Sort requests
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }

    int pos;
    for (i = 0; i < n; i++)
        if (head < req[i]) {
            pos = i;
            break;
        }

    printf("Order of movement: ");
    for (i = pos; i < n; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf("%d -> ", head);
    }

    // jump to beginning
    head = 0;
    seek += (size - 1); // jump cost

    for (i = 0; i < pos; i++) {
        seek += abs(req[i] - head);
        head = req[i];
        printf("%d -> ", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 2));

    return 0;
}
