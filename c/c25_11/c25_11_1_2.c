#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

//深度优先遍历：优先遍历孩子
//广度优先：一层一层遍历

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

typedef struct 
{
    char vertex[maxsize]; //顶点
    int arc[maxsize][maxsize]; //边
    int vertex_num;
    int edge_num;
}Mat_Grph;

int visited[maxsize];

int addArray(Mat_Grph* G)
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
    return 0;
}

void create_graph(Mat_Grph* G)
{
    G->vertex_num=9;
    G->edge_num=15;
    for(int i=0;i<G->vertex_num;i++)
    {
        G->vertex[i]='A'+i;
    }
    for(int i=0;i<G->vertex_num;i++)
    {
        for(int j=0;j<G->vertex_num;j++)
        {
            G->arc[i][j]=0;
        }
    }
    addArray(G);
    for(int i=0;i<G->vertex_num;i++)
    {
        for(int j=0;j<G->vertex_num;j++)
        {
            G->arc[j][i]=G->arc[i][j];
        }
    }
}

//深度遍历
void DFS(Mat_Grph* G,int i)
{
    visited[i]=1;
    printf("%c ",G->vertex[i]);
    for(int j=0;j<G->vertex_num;j++)
    {
        if(G->arc[i][j]==1&&visited[j]==0)
        {
            DFS(G,j);
        }
    }
}

//广度遍历


int testDFS()
{
    Mat_Grph G;
    create_graph(&G);
    for(int i=0;i<G.vertex_num;i++)
    {
        visited[i]=0;
    }
    DFS(&G,0);
    for(int i=0;i<G.vertex_num;i++)
    {
        visited[i]=0;
    }
    return 0;
}

int testBFS()
{
    Mat_Grph G;
    create_graph(&G);
    for(int i=0;i<G.vertex_num;i++)
    {
        visited[i]=0;
    }
    BFS(&G,0);
    for(int i=0;i<G.vertex_num;i++)
    {
        visited[i]=0;
    }
    return 0;
}