#include <stdio.h>

int main() {
    int files[50], n, startBlock, len, i, j;

    // Initialize all blocks as free (0 = free, 1 = allocated)
    for (i = 0; i < 50; i++)
        files[i] = 0;

    printf("Enter number of blocks already allocated: ");
    scanf("%d", &n);

    printf("Enter the blocks already allocated: ");
    for (i = 0; i < n; i++) {
        int block;
        scanf("%d", &block);
        files[block] = 1;
    }

    while (1) {
        printf("\nEnter the starting block and length of file: ");
        scanf("%d %d", &startBlock, &len);

        int count = 0;
        for (i = startBlock; i < (startBlock + len); i++) {
            if (files[i] == 0)
                count++;
        }

        if (count == len) {
            for (j = startBlock; j < (startBlock + len); j++) {
                files[j] = 1;
                printf("%d -> allocated\n", j);
            }
            printf("The file is allocated successfully.\n");
        } else {
            printf("The file cannot be allocated.\n");
        }

        printf("\nDo you want to enter more files? (1 for Yes / 0 for No): ");
        int ch;
        scanf("%d", &ch);
        if (ch == 0)
            break;
    }

    return 0;
}
