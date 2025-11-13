#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 10
#define MAX_COL 10
#define MAX_QUEUE 100

//坐标结构体
typedef struct
{
    int x;
    int y;
}pos;

// 队列结构体
typedef struct
{
    pos data[MAX_QUEUE];
    int front; 
    int rear;
}queue;

//前驱节点结构体
typedef struct
{
    int x;
    int y;
}preNode;

//初始化队列
void initQueue(queue* q)
{
    q->front=q->rear=0;
}

//判断队列是否为空
int queueEmpty(queue* q)
{
    return q->front==q->rear;
}

//判断队列是否已满
int queueFull(queue* q)
{
    return (q->rear+1)%MAX_QUEUE==q->front;
}

//入队
int eQueue(queue* q,pos p)
{
    if(queueFull(q))
    {
        return 0;
    }
    q->data[q->rear]=p;
    q->rear=(q->rear+1)%MAX_QUEUE;
    return 1;
}

// 出队
int deQueue(queue* q,pos* p)
{
    if(queueEmpty(q))
    {
        return 0;
    }
    *p=q->data[q->front];
    q->front=(q->front+1)%MAX_QUEUE;
    return 1;
}

//打印最短路径
void printPath(preNode pre[MAX_ROW][MAX_COL],pos start,pos end)
{
    pos path[MAX_ROW * MAX_COL];
    int count=0;
    pos curr=end;
    while(curr.x!=start.x||curr.y!=start.y)
    {
        path[count++]=curr;
        int px=pre[curr.x][curr.y].x;
        int py=pre[curr.x][curr.y].y;
        curr.x=px;
        curr.y=py;
        if(px==-1&&py==-1)
        {
            printf("迷宫无解!\n");
            return;
        }
    }
    path[count++]=start;
    printf("最短路径(坐标:行,列):\n");
    for(int i=count-1;i>= 0;i--)
    {
        printf("(%d,%d)",path[i].x,path[i].y);
        if(i!=0)
        {
            printf(" -> ");
        }
    }
    printf("\n");
    int maze_path[MAX_ROW][MAX_COL]={0};
    for(int i=0;i<count;i++)
    {
        maze_path[path[i].x][path[i].y]=2;
    }
    printf("迷宫最短路径(2表示路径):\n");
    for(int i=0;i<MAX_ROW;i++)
    {
        for(int j=0;j<MAX_COL;j++)
        {
            printf("%d ",maze_path[i][j]);
        }
        printf("\n");
    }
}

//队列求解迷宫(BFS)
int MazeSolveByQueue(int maze[MAX_ROW][MAX_COL],int row,int col)
{
    queue q;
    initQueue(&q);
    int visited[MAX_ROW][MAX_COL]={0};
    preNode pre[MAX_ROW][MAX_COL];
    pos start={0, 0};
    pos end={row-1,col-1};
    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            pre[i][j].x=-1;
            pre[i][j].y=-1;
        }
    }
    if(maze[start.x][start.y]==1||maze[end.x][end.y]==1)
    {
        printf("迷宫起点或终点被墙壁阻挡,无解!\n");
        return 0;
    }
    eQueue(&q,start);
    visited[start.x][start.y]=1;
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    while (!queueEmpty(&q))
    {
        pos curr;
        deQueue(&q,&curr);
        if(curr.x==end.x&&curr.y==end.y)
        {
            printPath(pre,start,end);
            return 1;
        }
        for(int i=0;i<4;i++)
        {
            int nx=curr.x+dir[i][0];
            int ny=curr.y+dir[i][1];
            if(nx>=0&&nx<row&&ny>=0&&ny<col&&maze[nx][ny]==0&&visited[nx][ny]==0)
            {
                pos next={nx,ny};
                eQueue(&q,next);
                visited[nx][ny]=1;
                pre[nx][ny].x=curr.x;
                pre[nx][ny].y=curr.y;
            }
        }
    }
    printf("迷宫无解!\n");
    return 0;
}

int main()
{
    int maze[MAX_ROW][MAX_COL]=
    {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };
    printf("=== 队列(BFS)求解迷宫 ===\n");
    MazeSolveByQueue(maze,MAX_ROW,MAX_COL);
    return 0;
}