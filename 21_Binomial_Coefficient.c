#include <stdio.h>

int findMin(int a, int b) {
    return (a < b) ? a : b;
}

int binomialCoefficient(int n, int k) {
    int dp[n + 1][k + 1];

    // Calculate binomial coefficient values using dynamic programming
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= findMin(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n = 5;
    int k = 2;
    int result = binomialCoefficient(n, k);

    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, result);

    return 0;
}
