//实验五
//求解n皇后问题
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N 100 

int n;                 
int* queenCol; 
int solutionCount = 0;

//初始化函数
void init(int n)
{
    queenCol=(int*)malloc(n*sizeof(int));
    if(queenCol==NULL)
    {
        printf("内存分配失败!\n");
        exit(1);
    }
    for(int i=0;i<n;i++)
    {
        queenCol[i]=-1;
    }
}

//判断第row行第col列是否可放置皇后
int isSafe(int row,int col)
{
    for (int i=0;i<row;i++)
    {
        if(queenCol[i]==col)
        {
            return 0;
        }
        if(abs(i-row)==abs(queenCol[i]-col))
        {
            return 0; 
        }
    }
    return 1;
}

//打印单个解
void printSolution()
{
    printf("第%d个解:\n",++solutionCount);
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(queenCol[i]==j)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("------------------------\n");
}

//放置第row行的皇后
void solveNQueens(int row)
{
    if(row==n)
    {
        printSolution();
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(row,col))
        { 
            queenCol[row]=col; 
            solveNQueens(row+1);  
            queenCol[row]=-1;
        }
    }
}

int main()
{
    printf("请输入皇后数量n(建议1≤n≤12,n=12时解较多,耐心等待):");
    scanf("%d",&n);
    if(n<1||n>MAX_N)
    {
        printf("n的取值范围为1~%d!\n",MAX_N);
        return 1;
    }
    init(n);
    solveNQueens(0);
    if(solutionCount==0)
    {
        printf("n=%d时,无有效解!\n",n);
    }
    else
    {
        printf("n=%d时,共找到%d个有效解!\n",n,solutionCount);
    }
    free(queenCol);
    return 0;
}