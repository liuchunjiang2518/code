//prim算法求最小生成树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
#define max 0x7fffffff

typedef struct
{
    char vertex[maxsize];
    int arc[maxsize][maxsize];
    int numVertex,numEdge;
}matGraph;

matGraph* createGraph()
{
    matGraph* G=(matGraph*)malloc(sizeof(matGraph));
    G->numVertex=9;
    G->numEdge=15;
    for(int i=0;i<G->numVertex;i++)
    {
        G->vertex[i]='A'+i;
    }
    for(int i=0;i<G->numVertex;i++)
    {
        for(int j=0;j<G->numVertex;j++)
        {
            if(i==j)
            {
                G->arc[i][j]==0;
            }
            else
            {
                G->arc[i][j]=max;
            }
        }
    }
    G->arc[0][1]=10;
    G->arc[0][5]=11;

    G->arc[1][2]=18;
    G->arc[1][6]=16;
    G->arc[1][8]=12;

    G->arc[2][3]=22;
    G->arc[2][8]=8;

    G->arc[3][4]=20;
    G->arc[3][6]=24;
    G->arc[3][7]=16;
    G->arc[3][8]=21;

    G->arc[4][5] = 26;
    G->arc[4][7] = 7;

    G->arc[5][6] = 17;
    
    G->arc[6][7] = 19;
    for(int i=0;i<G->numVertex;i++)
    {
        for(int j=0;j<G->numVertex;j++)
        {
            G->arc[j][i]=G->arc[i][j];
        }
    }
    return G;
}

void prim(matGraph* G)
{
    int min;
    int weight[maxsize];
    int indexVertex[maxsize];
    weight[0]=0;
    indexVertex[0]=0;
    for(int i=1;i<G->numVertex;i++)
    {
        weight[i]=G->arc[0][i];
        indexVertex[i]=0;
    }
    for(int i=1;i<G->numVertex;i++)
    {
        min=max;
        int k=0;
        for(int j=0;j<G->numVertex;j++)
        {
            if(weight[j]!=0&&weight[j]<min)
            {
                min=weight[j];
                k=j;
            }
        }
        printf("(%c,%c):%d\n",G->vertex[indexVertex[k]],G->vertex[k],G->arc[indexVertex[k]][k]);
        weight[k]=0;
        for(int j=0;j<G->numVertex;j++)
        {
            if(weight[j]!=0&&G->arc[k][j]<weight[j])
            {
                weight[j]=G->arc[k][j];
                indexVertex[j]=k;
            }
        }
    }
}

int main()
{
    matGraph* G=createGraph();
    prim(G);
    return 0;
}