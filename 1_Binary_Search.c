#include <stdio.h>

int binarySearch(int arr[], int l, int r, int t) {
    while (l <= r) {
        int m = l+(r-l)/2;
        if (arr[m] < t) l = m+1;
        else r = m-1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int t;
    printf("Enter the target number: ");
    scanf("%d", &t);

    int res = binarySearch(arr, 0, n - 1, t);
    if (res == -1) printf("Target not found in the array.\n");
    else printf("Target found at index %d.\n", res);

    return 0;
}
