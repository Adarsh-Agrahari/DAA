#include <stdio.h>

void findMinMax(int arr[], int low, int high, int* min, int* max) {
    int mid, min1, max1, min2, max2;

    // Base case: If there is only one element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // Base case: If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    // Divide the array into two halves
    mid = (low + high) / 2;
    findMinMax(arr, low, mid, &min1, &max1);
    findMinMax(arr, mid + 1, high, &min2, &max2);

    // Compare the minimum and maximum of the two halves
    if (min1 < min2) {
        *min = min1;
    } else {
        *min = min2;
    }

    if (max1 > max2) {
        *max = max1;
    } else {
        *max = max2;
    }
}

int main() {
    int arr[] = {4, 7, 2, 9, 1, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, size - 1, &min, &max);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
