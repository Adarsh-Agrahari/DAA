#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define I 32767
#define V 10

int graph[V][V];
int dist[V];
bool fin[V];

void dijkstra(int n, int src)
{
    for(int i = 0; i < n; i++)
    {
        dist[i] = I;
        fin[i] = false;
    }
    
    dist[src] = 0;
    
    for(int count = 0; count < n; count++)
    {
        // Finds the vertex with the minimum distance
        int u = -1;
        for(int i = 0; i < n; i++)
        {
            if(!fin[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        
        // Finalizes the vertex
        fin[u] = true;
        
        // Relaxes the adjacent vertices
        for(int v = 0; v < n; v++)
        {
            if(!fin[v] && graph[u][v] != 0)
            {
                if(dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix for the graph:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    
    dijkstra(n, src);
    
    printf("The Dijkstra's shortest path distances from the source vertex %d:\n", src);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
    
    return 0;
}
