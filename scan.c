#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, head, direction, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    int size;
    scanf("%d", &size);

    printf("Enter head movement direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    // Add start and end points
    req[n] = 0;
    req[n + 1] = size - 1;
    n += 2;

    // Sort the array
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

    if (direction == 1) { // moving towards higher end
        for (i = pos; i < n; i++) {
            seek += abs(req[i] - head);
            head = req[i];
            printf("%d -> ", head);
        }
        for (i = pos - 1; i >= 0; i--) {
            seek += abs(req[i] - head);
            head = req[i];
            printf("%d -> ", head);
        }
    } else { // moving towards lower end
        for (i = pos - 1; i >= 0; i--) {
            seek += abs(req[i] - head);
            head = req[i];
            printf("%d -> ", head);
        }
        for (i = pos; i < n; i++) {
            seek += abs(req[i] - head);
            head = req[i];
            printf("%d -> ", head);
        }
    }

    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 2));

    return 0;
}
