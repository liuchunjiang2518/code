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

//初始化
stack* initStack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->data=(int*)malloc(sizeof(int)*maxsize);
    s->top=-1;
    return s;
}

//判断非空
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

//入栈
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

//出栈
int popStack(stack* s)
{
    if(s->top==-1)
    {
        return 1;
    }
    printf("%d出栈\n",s->data[s->top]);
    s->top--;
}

//遍历栈
void traverseStack(stack* s)
{
    printf("遍历结果:");
    for(int i=0;i<s->top+1;i++)
    {
        printf("%d ",s->data[i]);
    }
    printf("\n");
}

int testStack()
{
    stack* s=initStack();
    for(int i=0;i<5;i++)
    {
        pushStack(s,i);
    }
    traverseStack(s);
    popStack(s);
    traverseStack(s);
    return 0;
}

//循环队列
typedef struct
{
    int* data;
    int front,rear;
}queue;

//初始化
queue* initQueue()
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->data=(int*)malloc(sizeof(int)*maxsize);
    q->front=0;
    q->rear=0;
    return q;
}

//入队
int eQueue(queue* q,int n)
{
    if((q->rear+1)%maxsize==q->front)
    {
        return 1;
    }
    q->data[q->rear]=n;
    printf("%d入队\n",n);
    q->rear=(q->rear+1)%maxsize;
    return 0;
}

//出队
int deQueue(queue* q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    printf("%d出队\n",q->data[q->front]);
    q->front=(q->front+1)%maxsize;
    return 0;
}

//测试队列
int testQueue()
{
    queue* q=initQueue();
    for(int i=0;i<5;i++)
    {
        eQueue(q,i);
    }
    deQueue(q);
    return 0;
}

int main()
{
    testQueue();
    //testStack();
    return 0;
}