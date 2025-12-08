#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int visited[MAXSIZE];

typedef struct MatGraph
{
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}MatGraph;

typedef struct Queue
{
    int data[MAXSIZE];
    int front;
    int rear;
}Queue;

Queue* initQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int enQueue(Queue* Q,int val)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return 1;
    }
    Q->data[Q->rear] = val;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 0;
}

int deQueue(Queue* Q,int* del)
{
    if(Q->rear == Q->front)
    {
        return 1;
    }
    *del = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 0;
}

void testEdge(MatGraph* G)
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
}

MatGraph* createGraph()
{
    MatGraph* G = (MatGraph*)malloc(sizeof(MatGraph));
    G->vertex_num = 9;
    G->edge_num = 15;
    for(int i = 0;i < G->vertex_num;i++)
    {
        G->vertex[i] = 'A' + i;
    }
    for(int i = 0;i < G->vertex_num;i++)
    {
        for(int j = 0;j < G->vertex_num;j++)
        {
            G->arc[i][j] = 0;
        }
    }
    testEdge(G);
    for(int i = 0;i < G->vertex_num;i++)
    {
        for(int j = 0;j < G->vertex_num;j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
    return G;
}

void dfs(MatGraph* G,int i)
{
    visited[i] = 1;
    printf("%c ",G->vertex[i]);
    for(int j = 0;j < G->vertex_num;j++)
    {
        if(G->arc[i][j] == 1 && visited[j] == 0)
        {
            dfs(G,j);
        }
    }
}

void bfs(MatGraph* G,int i)
{
    visited[i] = 1;
    printf("%c ",G->vertex[i]);
    Queue* Q = initQueue();
    enQueue(Q,i);
    while(Q->front != Q->rear)
    {
        deQueue(Q,&i);
        for(int j = 0;j < G->vertex_num;j++)
        {
            if(G->arc[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                printf("%c ",G->vertex[j]);
                enQueue(Q,j);
            }
        }
    }
}

int main()
{
    MatGraph* G = createGraph();
    dfs(G,0);
    return 0;
}