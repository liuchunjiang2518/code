#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAX 0x7fffffff

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

int enQueue(Queue* Q,int val);
int deQueue(Queue* Q,int* del);
Queue* initQueue();

void bfs(MatGraph* G,int i)
{
    visited[i] = 1;
    printf("");
    Queue* Q = initQueue();
    enQueue(Q,i);
    while(Q->front != Q->rear)
    {
        deQueue(Q,&i);
        for(int j = 0; j < G->vertex_num;j++)
        {
            if(G->arc[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                enQueue(Q,j);
                printf("");
            }
        }
    }
}

void dfs(MatGraph* G,int i)
{
    visited[i] = 1;
    printf("");
    for(int j = 0;j < G->vertex_num;j++)
    {
        if(G->arc[i][j] == 1 && visited[j] == 0)
        {
            dfs(G,j);
        }
    }
}


void prim(MatGraph* G)
{
    int i,j,k;
    int min;
    int weight[MAXSIZE];
    int vex_idx[MAXSIZE];
    weight[0] = 0;
    vex_idx[0] = 0;
    for(i = 1;i < G->vertex_num;i++)
    {
        weight[i] = G->arc[0][i];
        vex_idx[i] = 0;
    }
    for(i = 1;i < G->vertex_num;i++)
    {
        j = 0;
        k = 0;
        min = MAX;
        for(j;j < G->vertex_num;j++)
        {
            if(weight[j] != 0 && weight[j] < min)
            {
                min = weight[j];
                k = j;
            }
        }
        printf("(%c,%c) ",G->vertex[vex_idx[k]],G->vertex[k]);
        weight[k] = 0;
        for(j = 0;j < G->vertex_num;j++)
        {
            if(weight[j] != 0 && G->arc[j][k] < weight[j])
            {
                weight[j] = G->arc[j][k];
                vex_idx[j] = k;
            }
        }
    }
}