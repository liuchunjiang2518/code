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

void initGraphEdges(MatGraph* G)
{
    for(int i = 0;i < G->vertex_num;i++)
    {
        for(int j = 0;j < G->vertex_num;j++)
        {
            G->arc[i][j] = 0;
        }
    }
    int edges[15][2] =
    {
        {0,1}, {0,5},
        {1,2}, {1,6}, {1,8},
        {2,3}, {2,8},
        {3,4}, {3,6}, {3,7}, {3,8},
        {4,5}, {4,7},
        {5,6},
        {6,7}
    };
    for(int i = 0;i < 15;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        G->arc[u][v] = 1;
        G->arc[v][u] = 1;
    }
}

void initGraphVertexs(MatGraph* G)
{
    for(int i = 0;i < G->vertex_num;i++)
    {
        G->vertex[i] = 'A' + i;
    }
}

MatGraph* createGraph()
{
    MatGraph* G = (MatGraph*)malloc(sizeof(MatGraph));
    G->vertex_num = 9;
    G->edge_num = 15;
    initGraphVertexs(G);
    initGraphEdges(G);
    return G;
}

Queue* initQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int enQueue(Queue* Q,int val)
{
    if(Q->front == (Q->rear + 1) % MAXSIZE)
    {
        return 1;
    }
    Q->data[Q->rear] = val;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 0;
}

int deQueue(Queue* Q,int* del)
{
    if(Q->front == Q->rear)
    {
        return 1;
    }
    *del = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 0;
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
    MatGraph* G =createGraph();
    bfs(G,0);
    return 0;
}