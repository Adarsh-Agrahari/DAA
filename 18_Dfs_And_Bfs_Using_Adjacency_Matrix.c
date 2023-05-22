#include <stdio.h>
#include "queue_linked_list.c" 

void BFS(int G[][7], int start, int n) // n = dimension of the array
{
    int i = start, j;
    int visited[7]={0}; // make the visited array as 0

    printf("%d ", i);
    visited[i]=1;           // storing the first element and enqueuing it
    enqueue(i);

    while(!isEmpty())
    {
        i=dequeue();
        for(j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0) // if edge is 1, and j is not visited
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7]={0};

    if(visited[start]==0)
    {
        printf("%d ", start);
        visited[start]=1;
        for(int j=1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]==0)
            DFS(G,j,n);
        }
    }
}


int main()
{
    /*  Sample Graph
    
            1
           / \
          2   3
           \ /
            4
           / \
          5   6    
    
    */
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},   // index started from 1 
                   {0, 0, 1, 1, 0, 0, 0},   // 0th row&col filled with 0
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    // BFS(G, 4, 7);
    printf("\nBFS traversal :");
    BFS(G, 1, 7);

    // DFS(G,4,7);
    printf("\nDFS traversal :");
    DFS(G, 1, 7);

    return 0;

}