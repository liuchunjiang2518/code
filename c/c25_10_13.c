#include <stdio.h>
#include <stdlib.h>
#define maxsize 8

typedef int mytype;

typedef struct
{
    mytype* data;
    int front;
    int rear;
}Queue;

Queue* initQueue()
{
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->data=(mytype*)malloc(sizeof(mytype)*maxsize);
    q->front=0;
    q->rear=0;
    return q;
}

int eQueue(Queue* q,mytype n)
{
    if((q->rear+1)%maxsize==q->front)
    {
        return 1;
    }
    q->data[q->rear]=n;
    q->rear=(q->rear+1)%maxsize;
    return 0;
}

int deQueue(Queue* q,mytype* deldata)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    *deldata=q->data[q->front];
    q->front=(q->front+1)%maxsize;
    return 0;
}

int listQueue(Queue* q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    {
        int i=q->front;
        while(i!=q->rear)
        {
            printf("%d ",q->data[i]);
            i=(i+1)%maxsize;
        }
        return 0;
    }
}

// int main()
// {
//     Queue* myq=initQueue();
//     mytype* deldata;
//     eQueue(myq,10);
//     eQueue(myq,20);
//     eQueue(myq,30);
//     eQueue(myq,40);
//     eQueue(myq,50);
//     eQueue(myq,60);
//     eQueue(myq,70);
//     eQueue(myq,80);
//     deQueue(myq,deldata);
//     eQueue(myq,90);
//     listQueue(myq);
//     return 0;
// }

typedef struct QueueNode
{
    struct QueueNode* next;
    mytype data;
}queueNode;

typedef struct
{
    queueNode* front;
    queueNode* rear;
}queue;

queue* initQueue()
{
    queue* q=(queue*)malloc(sizeof(queue));
    queueNode* node=(queueNode*)malloc(sizeof(queueNode));
    node->data=0;
    node->next=NULL;
    q->front=node;
    q->rear=node;
    return q; 
}

void eQueue(queue* q,mytype n)
{
    queueNode* node=(queueNode*)malloc(sizeof(queueNode));
    node->data=n;
    node->next=NULL;
    q->rear->next=node;
    q->rear=node;
}

int deQueue(queue* q)
{
    queueNode* del=q->front->next;
    q->front->next=del->next;
    if(q->rear==del)
    {
        q->rear=q->front;
    }
    free(del);
    return 0;
}

