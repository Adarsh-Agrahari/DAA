#include <stdio.h>

// Function to find the maximum and minimum elements
void findMaxMin(int arr[], int n, int* max, int* min) {
    int i;
    // Initialize max and min to the first element of the array
    *max = arr[0];
    *min = arr[0];

    // Traverse the array and update max and min if necessary
    for (i = 1; i < n; i++) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

// Driver program
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, n, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
