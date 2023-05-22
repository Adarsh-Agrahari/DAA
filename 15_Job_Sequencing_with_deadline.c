#include <stdio.h>

// Function to perform Job Sequencing with Deadline
void jobSequencing(int profits[], int deadlines[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadlines[i] > maxDeadline)
            maxDeadline = deadlines[i];
    }

    int result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        result[i] = -1;

    for (int i = 0; i < n; i++) {
        int j = deadlines[i] - 1;
        while (j >= 0) {
            if (result[j] == -1) {
                result[j] = i;
                break;
            }
            j--;
        }
    }

    int totalProfit = 0;
    printf("Job Sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i]);
            totalProfit += profits[result[i]];
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

// Driver program
int main() {
    int profits[] = {35, 30, 25, 20, 15, 12, 5};
    int deadlines[] = {3, 4, 4, 2, 3, 1, 2};
    int n = sizeof(profits) / sizeof(profits[0]);

    jobSequencing(profits, deadlines, n);

    return 0;
}
