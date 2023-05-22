#include<stdio.h>
#include<stdlib.h>
#define I 32767
#define V 8


int cost[][8]={ {I,I,I,I,I,I,I,I},
                {I,I,25,I,I,I,5,I},
                {I,25,I,12,I,I,I,10},
                {I,I,12,I,8,I,I,I},
                {I,I,I,8,I,16,I,14},
                {I,I,I,I,16,I,20,18},
                {I,5,I,I,I,20,I,I},
                {I,I,10,I,14,18,I,I}
};
int near[8]={I,I,I,I,I,I,I,I};       
int t[2][6];  
int main()
{
    
    int n=7;
    int min=I;
    int u,v,i,j,k;
    //find the most min cost/edge
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;v=j;
            }
        }
    } 

    t[0][0]=u; t[1][0]=v;
    near[u]=near[v]=0;
    //initialize the near array for the first time
    for(i=1;i<=n;i++)  
    {
        if(near[i] != 0)
        {
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }   

    for(int i=1;i<n-1;i++)
    {
        //finding the min cost of the nearest array to put in final tree
        min=I;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < min)
            {
                min=cost[j][near[j]];
                k=j;
            }  
        }
        //updating tree array
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        //repeat or update the near array by checking it's indices are nearer to k(current vertex) or the previous already existing value
        for(int j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
            {
                near[j]=k;
            }
        }
    }
        //printing mst
        for(int i=0;i<n-1;i++)
        {
             
            printf("[ %d ", t[0][i] );
            printf(" %d ]",t[1][i]);
            printf("\n");
        }   
    
   
    return 0;
}