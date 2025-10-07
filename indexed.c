#include <stdio.h>

int main() {
    int files[50], indexBlock[50], i, j, n, index, choice;

    // Initialize all as free
    for (i = 0; i < 50; i++)
        files[i] = 0;

    while (1) {
        printf("\nEnter the index block: ");
        scanf("%d", &index);

        if (files[index] == 1) {
            printf("Block already allocated.\n");
            continue;
        }

        files[index] = 1;

        printf("Enter number of blocks needed for the file: ");
        scanf("%d", &n);

        printf("Enter the blocks to be allocated: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &indexBlock[i]);
            if (files[indexBlock[i]] == 0)
                files[indexBlock[i]] = 1;
            else {
                printf("Block %d already allocated.\n", indexBlock[i]);
                i--;
            }
        }

        printf("File allocated successfully.\n");
        printf("Index Block: %d\nBlocks: ", index);
        for (i = 0; i < n; i++)
            printf("%d ", indexBlock[i]);
        printf("\n");

        printf("\nDo you want to enter more files? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
    }

    return 0;
}
