#include<stdio.h>
#include<stdlib.h>
#define I 32767

int edges[3][9]={
    {1  ,1 ,2  ,2 , 3 ,4  ,4  ,5  ,5 },
    {2  ,6 ,3  ,7 , 4 ,5  ,7  ,6  ,7 },
    {25 ,5 ,12 ,10, 8 ,16 ,14 ,20 ,18}
};
 

int set[8]= {- 1, -1,-1,-1,-1,-1,-1,-1};
int included[9]={0};
int t[2][6];

void PrintMCST(){
    printf("\nMinimum Cost Spanning Tree Edges\n");
    for (int i=0; i<6; i++){
        printf("[ %d ", t[0][i] );
        printf(" %d ]",t[1][i]);
        printf("\n");
    }
    
}

void unionset(int u, int v)
{
    if(set[u]<set[v])
    {
        set[u]=set[u]+set[v];
        set[v]=u;
    }
    else{
        set[v]=set[u]+set[v];
        set[u]=v;
    }
}

int find(int u)
{
    int x=u;
    //int v=0;
    while(set[x]>0)
    {
        x=set[x];
    }
    
    // while (u != x){
    //     v = set[u];
    //     set[u] = x;
    //     u = v;
    // }
    return x;
}

int main()
{
    int i=0,j,k,n=7,min,e=9,u,v;
    
    while(i<n-1)
    {
        //find minimum edge
        min=I;
        for(j=0;j<e;j++)
        {
             if(included[j]==0 && edges[2][j]<min)   
             {
                min=edges[2][j];
                k=j; //k points to minimum cost
                u=edges[0][j];
                v=edges[1][j];
             }
        }
        // Check if the selected min cost edge (u, v) forming a cycle or not
        if(find(u)!=find(v))
        {
            t[0][i]=u;
            t[1][i]=v;
    
            unionset(find(u),find(v));
            printf("\n");//union of it's parents ..thus union of find(u) and find(v)
            i++;
        }
        included[k]=1;
    }
    PrintMCST();
    return 0;
}

