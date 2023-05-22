#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define I 32767
#define V 4
//#define E 5

int graph[4][4]={{0,50,100,0},
                 {50,0,30,200},
                 {100,30,0,20},
                 {0,300,20,0}};
int dist[]={0,I,I,I};
bool fin[V]={false};

void dijkstra(int src)
{
    
    for(int count=0; count<V;count++)
    {
        //finds min cost out of the relaxed vertices
        int u=-1;
        for(int i=0;i<V;i++)
        {
            if(!fin[i] && (u==-1 || dist[i]<dist[u]))
            {
                u=i;
            }
        }
        //Finalizes the vertex
        fin[u]=true;
        // printf("%d \n:",count);
        // for(int x=0; x<V;x++)
        // {
            
        //     printf("%d ",fin[x]);
        // }
        // printf("\n");
        //relaxes the adjacent vertices
        for(int v=0;v<V;v++)
        {
            if(!fin[v] && graph[u][v]!=0)
            {
                //dist[v]=min(dist[v],dist[u]+graph[u][v]);
                if(dist[u]+graph[u][v]<dist[v]) dist[v]=dist[u]+graph[u][v];
              //  else dist[v]=dist[v];
            }
        }
        //printf("%d :",count);
        // for(int x=0; x<V;x++)
        // {
            
        //     printf("%d ",dist[x]);
        // }
        // printf("\n");
        
    }
   
}



int main()
{
    int src=0;
    dijkstra(src);
   // PrintMST
   printf("The dijkstra MST: \n");
    for(int x=0; x<V;x++)
        {
            
            printf("%d ",dist[x]);
        }
   return 0;
}