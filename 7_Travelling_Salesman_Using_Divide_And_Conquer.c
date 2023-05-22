#include <stdio.h>
#include <limits.h>
#define I INT_MAX
#define SIZE 4 // Number of cities

// Function to find the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the cost of a path
int calculateCost(int graph[SIZE][SIZE], int path[], int n) {
    int cost = 0;

    for (int i = 0; i < n - 1; i++) {
        cost += graph[path[i]][path[i + 1]];
    }

    cost += graph[path[n - 1]][path[0]]; // Return to the starting city
    return cost;
}

// Function to find the minimum cost path using divide and conquer
int tspDivideAndConquer(int graph[SIZE][SIZE], int currPos, int visited[], int count, int path[], int minCost, int cost) {
    // If all cities have been visited
    if (count == SIZE && graph[currPos][0]) {
        if (cost + graph[currPos][0] < minCost) {
            // Update the minimum cost
            minCost = cost + graph[currPos][0];

            // Update the path
            for (int i = 0; i < SIZE; i++) {
                path[i] = visited[i];
            }
            path[SIZE] = visited[0];
        }
        return minCost;
    }

    // Recursively visit each city not yet visited
    for (int i = 0; i < SIZE; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = 1;
            minCost = tspDivideAndConquer(graph, i, visited, count + 1, path, minCost, cost + graph[currPos][i]);
            visited[i] = 0;
        }
    }

    return minCost;
}

// Function to solve the Traveling Salesman Problem using divide and conquer
void solveTSP(int graph[SIZE][SIZE]) {
    int visited[SIZE]; // To keep track of visited cities
    int path[SIZE + 1]; // To store the final path
    int minCost = I;

    // Initialize visited array
    for (int i = 0; i < SIZE; i++) {
        visited[i] = 0;
    }

    // Start from the first city
    visited[0] = 1;

    // Find the minimum cost path using divide and conquer
    minCost = tspDivideAndConquer(graph, 0, visited, 1, path, minCost, 0);

    // Print the minimum cost and path
    printf("Minimum Cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i <= SIZE; i++) {
        printf("%d ", path[i]);
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        // {0, 10, 15, 20},
        // {10, 0, 35, 25},
        // {15, 35, 0, 30},
        // {20, 25, 30, 0}
        
        {0,1,2,3},
        {1,0,4,5},
        {2,4,0,6},
        {3,5,6,0}
    };

    solveTSP(graph);

    return 0;
}
