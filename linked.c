#include <stdio.h>

int main() {
    int files[50], i, start, len, k, j, c;

    // Initialize all as free
    for (i = 0; i < 50; i++)
        files[i] = 0;

    while (1) {
        printf("\nEnter the starting block and the length of the file: ");
        scanf("%d %d", &start, &len);

        k = len;
        if (files[start] == 0) {
            for (j = start; j < (start + k); j++) {
                if (files[j] == 0) {
                    files[j] = 1;
                    printf("%d -> allocated\n", j);
                } else {
                    printf("%d -> already allocated\n", j);
                    k++;
                }
            }
            printf("The file is allocated successfully.\n");
        } else {
            printf("Starting block is already allocated.\n");
        }

        printf("\nDo you want to enter more files? (1 for Yes / 0 for No): ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }

    return 0;
}
