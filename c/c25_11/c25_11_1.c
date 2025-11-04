//求权重
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

int idx=0;
int weight[]={100,42,15,-1,-1,27,-1,-1,58,28,13,5,-1,-1,8,-1,-1,15,-1,-1,30,-1,-1};

void createTree(treeNode** T)
{
    int idata=weight[idx++];
    if(idata==-1)
    {
        *T=NULL;
        return;
    }
    else
    {
        *T=(treeNode*)malloc(sizeof(treeNode));
        (*T)->data=idata;
        createTree(&(*T)->left);
        createTree(&(*T)->right);
    }
}

int wpl(treeNode** T)
{
    if(T==NULL)
    {
        return 0;
    }
    treeNode* queue[maxsize];
    int front=0;
    int rear=0;
    int wpl=0;
    int depth=0;
    queue[rear]=*T;
    rear=(rear+1)%maxsize;
    while(rear!=front)
    {
        int count=(rear-front+maxsize)%maxsize;
        while(count>0)
        {
            treeNode* curr=queue[front];
            front=(front+1)%maxsize;
            if(curr->left==NULL&&curr->right==NULL)
            {
                wpl+=depth*curr->data;
            }
            if(curr->left!=NULL)
            {
                queue[rear]=curr->left;
                rear=(rear+1)%maxsize;
            }
            if(curr->right!=NULL)
            {
                queue[rear]=curr->right;
                rear=(rear+1)%maxsize;
            }
            count--; 
        }
        depth++;
    }
    printf("权重：%d",wpl);
    return wpl;
}

int main()
{
    treeNode* root=NULL;
    createTree(&root);
    wpl(&root);
    return 0;
}