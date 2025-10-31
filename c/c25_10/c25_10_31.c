//求最大深度，层序遍历
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define maxsize 100

typedef struct treeNode
{
   char data;
   struct treeNode* left;
   struct treeNode* right;
}treeNode;

typedef struct
{
    treeNode** data;
    int front,rear;
}queue;

char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;

void createTree(treeNode** T)
{
    char ch=str[idx++];
    if(ch=='#')
    {
        *T=NULL;
        return;
    }
    else
    {
        *T=(treeNode*)malloc(sizeof(treeNode));
        (*T)->data=ch;
        createTree(&(*T)->left);
        createTree(&(*T)->right);
    }
}

queue* initQueue()
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->data=(treeNode**)malloc(sizeof(treeNode*)*maxsize);
    q->front=0;
    q->rear=0;
    return q;
}

int nonEmpty(queue* q)
{
    if(q->front==q->rear)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int eQueue(queue* q,treeNode* T)
{
    if((q->rear+1)%maxsize==q->front)
    {
        return 1;
    }
    else
    {
        q->data[q->rear]=T;
        q->rear=((q->rear+1)%maxsize);
        return 0;
    }
}

int deQueue(queue* q,treeNode** del)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else
    {
        *del=q->data[q->front];
        q->front=((q->front+1)%maxsize);
        return 0;
    }
}

//获取队列元素个数
int queueSize(queue* q)
{
    return (q->rear-q->front+maxsize)%maxsize;
}

int maxDepth(treeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int depth=0;
    queue* q=initQueue();
    eQueue(q,root);
    while(nonEmpty(q))
    {
        int count=queueSize(q);
        while(count>0)
        {
            treeNode* curr=NULL;
            deQueue(q,&curr);
            if(curr->left!=NULL)
            {
                eQueue(q,curr->left);
            }
            if(curr->right!=NULL)
            {
                eQueue(q,curr->right);
            }
            count--;
        }
        depth++;
    }
    printf("深度:%d ",depth);
    fflush(stdout);
    sleep(10);
}

int main()
{
    treeNode* root=NULL;
    createTree(&root);
    maxDepth(root);
    return 0;
}