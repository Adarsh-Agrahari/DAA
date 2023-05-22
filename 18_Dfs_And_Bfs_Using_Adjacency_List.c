#include <stdio.h>
#include <stdlib.h>
#define N 100

// Function to initialize the adjacency list
void initializeGraph(int adj[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
}

// Function to add an edge between two vertices in the graph
void addEdge(int adj[][N], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to perform Depth First Search (DFS) on the graph
void dfs(int adj[][N], int n, int s) {
    int stack[N];
    int top = -1;
    int visited[N] = {0};

    stack[++top] = s;
    visited[s] = 1;

    printf("Depth First Search (DFS) starting from vertex %d: ", s);

    while (top != -1) {
        int curr = stack[top--];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Function to perform Breadth First Search (BFS) on the graph
void bfs(int adj[][N], int n, int s) {
    int queue[N];
    int front = 0, rear = -1;
    int visited[N] = {0};

    queue[++rear] = s;
    visited[s] = 1;

    printf("Breadth First Search (BFS) starting from vertex %d: ", s);

    while (front <= rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int n = 6;

    int adj[N][N];

    initializeGraph(adj, n);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);


    int s = 0;

    dfs(adj, n, s);
    bfs(adj, n, s);

    return 0;
}
