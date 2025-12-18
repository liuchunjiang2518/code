#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000

typedef struct MatGraph
{
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}MatGraph;

void testEdge(MatGraph* G)
{
    G->arc[0][1] = 1;
    G->arc[0][2] = 5;
    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;
    G->arc[2][4] = 1;
    G->arc[2][5] = 7;
    G->arc[3][4] = 2;
    G->arc[3][6] = 3;
    G->arc[4][5] = 3;
    G->arc[4][6] = 6;
    G->arc[4][7] = 9;
    G->arc[5][7] = 5;
    G->arc[6][7] = 2;
    G->arc[6][8] = 7;
    G->arc[7][8] = 4;
}

MatGraph* createGraph()
{
    MatGraph* G = (MatGraph*)malloc(sizeof(MatGraph));
    G->vertex_num = 9;
    G->edge_num = 16;
    for(int i = 0;i < G->vertex_num;i++)
    {
        G->vertex[i] = 'A' + i;
    }
    for(int i = 0;i <G->vertex_num;i++)
    {
        for(int j = 0;j < G->vertex_num;j++)
        {
            if(i == j)
            {
                G->arc[i][j] = 0;
            }
            else
            {
                G->arc[i][j] = MAX;
            }
        }
    }
    testEdge(G);
    for(int i = 0;i <G->vertex_num;i++)
    {
        for(int j = 0;j < G->vertex_num;j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
    return G;
}

int choose(int* distance,int* found,int num)
{
    int min = MAX;
    int next = -1;
    for(int i = 0;i < num;i++)
    {
        if(distance[i] < min && found[i] == 0)
        {
            min = distance[i];
            next = i;
        }
    }
    return next;
}

void dijkstra(MatGraph* G,int begin)
{
    int found[MAXSIZE];
    int path[MAXSIZE];
    int distance[MAXSIZE];
    for(int i = 0;i < G->vertex_num;i++)
    {
        found[i] = 0;
        path[i] = -1;
        distance[i] = G->arc[begin][i];
    }
    distance[begin] = 0;
    found[begin] = 1;
    printf("%c ",G->vertex[begin]);
    int next;
    for(int i = 1;i < G->vertex_num;i++)
    {
        next = choose(distance,found,G->vertex_num);
        printf("%c ",G->vertex[next]);
        found[next] = 1;
        for(int j = 0;j < G->vertex_num;j++)
        {
            if(found[j] == 0)
            {
                if(distance[next] + G->arc[next][j] < distance[j])
                {
                    distance[j] = distance[next] + G->arc[next][j];
                    path[j] = next;
                }
            }
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
        for(int j = 0;j < G->vertex_num;j++)
        {
            if(weight[i] != 0 && weight[i] < min)
            {
                min = weight[j];
                k = j;
            }
        }
        printf("");
        weight[k] = 0;
        for(int j = 0;j < G->vertex_num;j++)
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
    MatGraph* G = createGraph();
    dijkstra(G,0);
    return 0; 
}