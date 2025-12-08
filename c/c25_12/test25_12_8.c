#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MAX 0x7fffffff

typedef struct MatGraph
{
    char vertex[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;
}MatGraph;

void testEdge(MatGraph* G)
{
    G->arc[0][1] = 10;
    G->arc[0][5] = 11;
    G->arc[1][2] = 18;
    G->arc[1][6] = 16;
    G->arc[1][8] = 12;
    G->arc[2][3] = 22;
    G->arc[2][8] = 8;
    G->arc[3][4] = 20;
    G->arc[3][6] = 24;
    G->arc[3][7] = 16;
    G->arc[3][8] = 21;
    G->arc[4][5] = 26;
    G->arc[4][7] = 7;
    G->arc[5][6] = 17;
    G->arc[6][7] = 19;
}

MatGraph* createGraph()
{
    MatGraph* G = (MatGraph*)malloc(sizeof(MatGraph));
    G->edge_num = 15;
    G->vertex_num = 9;
    for(int i = 0;i < G->vertex_num;i++)
    {
        G->vertex[i] = 'A' + i;
    }
    for(int i = 0;i < G->vertex_num;i++)
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
    for(int i = 0;i < G->vertex_num;i++)
    {
        for(int j = 0;j < G->vertex_num;j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }
    return G;
}

void prim(MatGraph* G)
{
    int i,j,k;
    int min;
    int weight[MAXSIZE];
    int vex_index[MAXSIZE];
    weight[0] = 0;
    vex_index[0] = 0;
    for(i = 1;i < G->vertex_num;i++)
    {
        weight[i] = G->arc[0][i];
        vex_index[i] = 0;
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
        printf("(%c,%c)\n",G->vertex[vex_index[k]],G->vertex[k]);
        weight[k] = 0;
        for(j = 0;j < G->vertex_num;j++)
        {
            if(weight[j] != 0 && G->arc[j][k] < weight[j])
            {
                weight[j] = G->arc[j][k];
                vex_index[j] = k;
            }
        }
    }
}

int main()
{
    MatGraph* G = createGraph();
    prim(G);
    return 0;
}