//实验二
//栈和队列基本运算算法设计
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

//栈
typedef struct 
{
    int* data;
    int top;
}stack;

stack* initStack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->data=(int*)malloc(sizeof(int)*maxsize);
    s->top=-1;
    return s;
}

int stackNonEmpty(stack* s)
{
    if(s->top==-1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int pushStack(stack* s,int n)
{
    if(s->top==maxsize-1)
    {
        return 1;
    }
    s->top++;
    s->data[s->top]=n;
    printf("%d入栈\n",n);
    return 0;
}

int popStack(stack* s)
{
    if(s->top==-1)
    {
        return 1;
    }
    s->top--;
}

