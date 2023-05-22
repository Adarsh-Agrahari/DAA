#include <stdio.h>
#define V 100

// Function to initialize the adjacency matrix
void initializeGraph(int adj[][V], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices in the graph
void addEdge(int adj[][V], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to print the adjacency matrix
void printGraph(int adj[][V], int n) {
    printf("Graph represented by Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        
    }
}

int main() {
    int n = 5;
    int adj[V][V];

    initializeGraph(adj, n);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, n);

    return 0;
}
