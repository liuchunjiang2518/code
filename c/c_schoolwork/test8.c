//实验八
//图的算法设计
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100

int visited[maxsize];

typedef struct
{
    char vertex[maxsize];
    int arc[maxsize][maxsize];
    int numVertex,numEdge;
}matGraph;

int addArc(matGraph* G)
{
    G->arc[0][1] = 1;
    G->arc[0][5] = 1;
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;
    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;
    G->arc[5][6] = 1;
    G->arc[6][7] = 1;
    for(int i=0;i<G->numVertex;i++)
    {
        for(int j=0;j<G->numVertex;j++)
        {
            G->arc[j][i]=G->arc[i][j];
        }
    }
    return 0;
}

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
            G->arc[i][j]=0;
        }
    }
    addArc(G);
    return G;
}

//深度遍历
void DFS(matGraph* G,int i)
{
    visited[i]=1;
    printf("%c ",G->vertex[i]);
    for(int j=0;j<G->numVertex;j++)
    {
        if(G->arc[i][j]==1&&visited[j]==0)
        {
            DFS(G,j);
        }
    }
}

//广度遍历
typedef struct
{
    int data[maxsize];
    int front,rear;
}queue;

queue* initQueue()
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->front=0;
    q->rear=0;
    return q;
}

int eQueue(queue* q,int n)
{
    if((q->rear+1)%maxsize==q->front)
    {
        return 1;
    }
    q->data[q->rear]=n;
    q->rear=(q->rear+1)%maxsize;
}

int deQueue(queue* q)
{
    if(q->rear==q->front)
    {
        return 1;
    }
    int res=q->data[q->front];
    q->front=(q->front+1)%maxsize;
    return res;
}

void BFS(matGraph* G)
{
    int i=0;
    visited[i]=1;
    printf("%c ",G->vertex[i]);
    queue* q=initQueue();
    eQueue(q,i);
    while(q->front!=q->rear)
    {
        i=deQueue(q);
        for(int j=0;j<G->numVertex;j++)
        {
            if(G->arc[i][j]==1&&visited[j]==0)
            {    
                visited[j]=1;
                printf("%c ",G->vertex[j]);
                eQueue(q,j);
            }
        }
    }
}

int main()
{
   matGraph* G=createGraph();
   BFS(G);
   //DFS(G,0);
   return 0;
}