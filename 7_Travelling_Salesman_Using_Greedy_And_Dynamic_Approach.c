// C program to perform the travelling salesman problem using both greedy and dynamic programming approach.
#include <stdio.h>
#include <limits.h>
#define I INT_MAX
#define MAX_CITIES 10

int n, cost[MAX_CITIES][MAX_CITIES];

int min(int a, int b) {
    return a < b ? a : b;
}

// Greedy approach
int tsp_greedy(int start) {
    int visited[MAX_CITIES] = { 0 };
    visited[start] = 1;
    int current = start;
    int total_cost = 0;
    for (int i = 0; i < n - 1; i++) {
        int next = -1;
        int min_cost = I;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && cost[current][j] < min_cost) {
                next = j;
                min_cost = cost[current][j];
            }
        }
        visited[next] = 1;
        current = next;
        total_cost += min_cost;
    }
    total_cost += cost[current][start];
    return total_cost;
}

// Dynamic programming approach
int memo[MAX_CITIES][1 << MAX_CITIES];

int tsp_dp(int current, int visited) {
    if (visited == (1 << n) - 1) {
        return cost[current][0];
    }
    if (memo[current][visited] != -1) {
        return memo[current][visited];
    }
    int min_cost = I;
    for (int i = 0; i < n; i++) {
        if (!(visited & (1 << i))) {
            int subproblem_cost = cost[current][i] + tsp_dp(i, visited | (1 << i));
            min_cost = min(min_cost, subproblem_cost);
        }
    }
    memo[current][visited] = min_cost;
    return min_cost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    // Initialize memoization array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }
    // Run greedy approach
    int start = 0;
    int greedy_cost = tsp_greedy(start);
    printf("Greedy approach: %d\n", greedy_cost);
    // Run dynamic programming approach
    int dp_cost = tsp_dp(start, 1);
    printf("Dynamic programming approach: %d\n", dp_cost);
    return 0;
}


// Output :
// Enter the number of cities: 4
// Enter the cost matrix:
// 0 1 2 3
// 1 0 4 5
// 2 4 0 6
// 3 5 6 0
// Greedy approach: 14
// Dynamic programming approach: 14
