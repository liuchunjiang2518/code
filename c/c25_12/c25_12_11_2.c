#include <stdio.h>
#define MAXSIZE 10
#define MAX 10

int hash_table[MAXSIZE];

void initHash()
{
    for(int i = 0;i < MAXSIZE;i++)
    {
        hash_table[i] = -1;
    }
}

void insertHash(int key)
{
    int idx = key % MAXSIZE;
    while(hash_table[idx] != -1)
    {
        idx = (idx + 1) % MAXSIZE;
    }
    hash_table[idx] = key;
}

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

int visited[MAXSIZE];
Queue* initQueue();
int enQueue(Queue* Q,int val);
int deQueue(Queue* Q,int* del);

void bfs(MatGraph* G,int i)
{
    visited[i] = 1;
    printf("");
    Queue* Q = initQueue();
    enQueue(Q,i);
    while(Q->front != Q->rear)
    {
        deQueue(Q,&i);
        for(int j = 0;j < G->vertex_num;j++)
        {
            if(visited[j] == 0 && G->arc[i][j] == 1)
            {
                enQueue(Q,j);
                visited[j] = 1;
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
        printf("");
        for(j = 1;j < G->vertex_num;j++)
        {
            if(weight[j] != 0 && G->arc[j][k] < weight[j])
            {
                weight[j] = G->arc[j][k];
                vex_idx[j] = k;
            }
        }
    }
}

int main()
{
    int keys[] = {23,45,12,34,56,78};
    initHash();
    int len = sizeof(keys) / sizeof(keys[0]);
    for(int i =0;i < len;i++)
    {
        insertHash(keys[i]);
    }
    for(int i =0;i < MAXSIZE;i++)
    {
        if(hash_table[i] == -1)
        {
            printf("NULL ");
        }
        else
        {
            printf("%d ",hash_table[i]);
        }
    }
    return 0;
}