#include <stdio.h>
#include <stdlib.h>

#define I 32767
#define MAX_EDGES 100

void unionset(int u, int v, int* set) {
    if (set[u] < set[v]) {
        set[u] = set[u] + set[v];
        set[v] = u;
    } else {
        set[v] = set[u] + set[v];
        set[u] = v;
    }
}

int find(int u, int* set) {
    int x = u;
    while (set[x] > 0) {
        x = set[x];
    }
    return x;
}

int main() {
    int V, E;
    // ------------------------------------------------------------
    // User Input
    // ------------------------------------------------------------
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    int edges[3][MAX_EDGES];

    printf("Enter the edges in the format (u v cost):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[0][i], &edges[1][i], &edges[2][i]);
    }
    // ------------------------------------------------------------
    // Input 1
    // ------------------------------------------------------------
    // V=7,E=9;
    // int edges[3][MAX_EDGES]={
    //     {1  ,1 ,2  ,2 , 3 ,4  ,4  ,5  ,5 },
    //     {2  ,6 ,3  ,7 , 4 ,5  ,7  ,6  ,7 },
    //     {25 ,5 ,12 ,10, 8 ,16 ,14 ,20 ,18}
    // };
    // ------------------------------------------------------------
    // Minimum Cost Spanning Tree Edges
    // [ 1  6 ]
    // [ 3  4 ]
    // [ 2  7 ]
    // [ 2  3 ]
    // [ 4  5 ]
    // [ 5  6 ]
    // ------------------------------------------------------------
    // Input 2
    // ------------------------------------------------------------
    // V=4,E=5;
    // int edges[3][MAX_EDGES]={
    //     {0,0,1,1,2},
    //     {1,3,3,2,3},
    //     {2,6,8,3,1}
    // };
    // ------------------------------------------------------------
    // Minimum Cost Spanning Tree Edges
    // [ 2  3 ]
    // [ 0  1 ]
    // [ 1  2 ]
    // ------------------------------------------------------------
    int set[V + 1];
    int included[MAX_EDGES] = {0};
    int t[2][6];

    for (int i = 0; i <= V; i++) {
        set[i] = -1;
    }

    int i = 0, j, k, min, u, v;

    while (i < V - 1) {
        min = I;
        for (j = 0; j < E; j++) {
            if (included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        if (find(u, set) != find(v, set)) {
            t[0][i] = u;
            t[1][i] = v;
            unionset(find(u, set), find(v, set), set);
            printf("\n");
            i++;
        }
        included[k] = 1;
    }
    printf("\nMinimum Cost Spanning Tree Edges\n");
    for (int i = 0; i < V-1; i++) {
        printf("[ %d ", t[0][i]);
        printf(" %d ]", t[1][i]);
        printf("\n");
    }

    return 0;
}
