#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices
#define E 8 // Number of edges
#define I INT_MAX

// Function to print the distance array
void printDistances(int dist[]) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == I)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

// Function to implement the Bellman-Ford algorithm
void bellmanFord(int graph[V][V], int source) {
    int dist[V];

    // Initialize distances from the source vertex to all other vertices as INFINITE
    for (int i = 0; i < V; i++) {
        dist[i] = I;
    }
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                int weight = graph[u][v];

                if (dist[u] != I && weight != I && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            int weight = graph[u][v];

            if (dist[u] != I && weight != I && dist[u] + weight < dist[v]) {
                printf("Graph contains negative-weight cycle\n");
                return;
            }
        }
    }

    // Print the distances
    printDistances(dist);
}

int main() {
    int graph[V][V] = {
        {0, -1, 4, I, I},
        {I, 0, 3, 2, 2},
        {I, I, 0, I, I},
        {I, 1, 5, 0, I},
        {I, I, I, -3, 0}
    };

    int source = 0; // Source vertex

    // Function call
    bellmanFord(graph, source);

    return 0;
}
