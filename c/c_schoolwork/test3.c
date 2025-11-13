#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 10  //迷宫最大行数
#define MAX_COL 10  //迷宫最大列数
#define MAX_STACK 100  //栈最大容量

//坐标结构体
typedef struct
{
    int x;
    int y;
}pos;

//栈结构体
typedef struct
{
    pos data[MAX_STACK];
    int top;
}stack;

//初始化栈
void initStack(stack* s)
{
    s->top=-1;
}

//判断栈是否为空
int stackEmpty(stack* s)
{
    return s->top==-1;
}

//入栈
int pushStack(stack* s,pos p)
{
    if(s->top==MAX_STACK-1)
    {
        return 0;
    }
    s->data[++s->top]=p;
    return 1;
}

// 出栈
int popStack(stack* s,pos* p)
{
    if(stackEmpty(s))
    {
        return 0;
    }
    *p=s->data[s->top--];
    return 1;
}

//获取栈顶元素
int getTop(stack* s,pos* p)
{
    if(stackEmpty(s))
    {
        return 0;
    }
    *p=s->data[s->top];
    return 1;
}

//打印迷宫和路径(1:墙壁,0:未走,2:路径)
void printMaze(int maze[MAX_ROW][MAX_COL],int row,int col,stack* path)
{
    int temp_maze[MAX_ROW][MAX_COL];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp_maze[i][j]=maze[i][j];
        }
    }
    for(int i=0;i<=path->top;i++)
    {
        temp_maze[path->data[i].x][path->data[i].y]=2;
    }
    printf("迷宫路径(2表示路径):\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",temp_maze[i][j]);
        }
        printf("\n");
    }
}

//栈求解迷宫(DFS)
int mazeSolveByStack(int maze[MAX_ROW][MAX_COL],int row,int col)
{
    stack path;
    initStack(&path);
    int visited[MAX_ROW][MAX_COL]={0}; 
    pos start={0,0};
    pos end={row-1,col-1};
    if(maze[start.x][start.y]==1||maze[end.x][end.y]==1)
    {
        printf("迷宫起点或终点被墙壁阻挡,无解!\n");
        return 0;
    }
    pushStack(&path, start);
    visited[start.x][start.y]=1;
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    while (!stackEmpty(&path))
    {
        pos curr;
        getTop(&path,&curr);
        if(curr.x==end.x&&curr.y==end.y)
        {
            printMaze(maze,row,col,&path);
            return 1;
        }
        int found=0; 
        for(int i=0;i<4;i++)
        {
            int nx=curr.x+dir[i][0];
            int ny=curr.y+dir[i][1];
            if(nx>=0&&nx<row&&ny>=0&&ny<col&&maze[nx][ny]==0&& visited[nx][ny]==0)
            {
                pos next={nx,ny};
                pushStack(&path,next);
                visited[nx][ny]=1;
                found=1;
                break;
            }
        }
        if(!found)
        {
            popStack(&path,&curr);
        }
    }
    printf("迷宫无解！\n");
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
    printf("=== 栈(DFS)求解迷宫 ===\n");
    mazeSolveByStack(maze,MAX_ROW,MAX_COL);
    return 0;
}