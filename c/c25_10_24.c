//线索二叉树--中序遍历线索化
#include <stdio.h>
#include <stdlib.h>

typedef struct threadNode
{
    char data;
    struct threadNode* left;
    struct threadNode* right;
    int ltag,rtag;
}threadNode;

char str[]="ABDH##I##EJ###CF##G##";
int idx=0;
threadNode* prev;

void createTree(threadNode** T)
{
    char ch=str[idx++];
    if(ch=='#')
    {
        *T=NULL;
        return;
    }
    else
    {
        *T=(threadNode*)malloc(sizeof(threadNode));
        (*T)->data=ch;
        createTree(&(*T)->left);
        if((*T)->left!=NULL)
        {
            (*T)->ltag=0;
        }
        createTree(&(*T)->right);
        if((*T)->right!=NULL)
        {
            (*T)->rtag=0;
        }
    }
}

void threading(threadNode* T)
{
    if(T!=NULL)
    {
        threading(T->left);
        if(T->left==NULL)
        {
            T->left=prev;
            T->ltag=1;
        }
        if(prev->right==NULL)
        {
            prev->right=T;
            prev->rtag=1;
        }
        prev=T;
        threading(T->right);
    }
}

void inOrderThreading(threadNode** head,threadNode* T)
{
    *head=(threadNode*)malloc(sizeof(threadNode));
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->right=*head;
    //二叉树为空
    if(T==NULL)
    {
        (*head)->left=*head;
    }
    else
    {
        (*head)->left=T;
        prev=(*head);
        threading(T);
        prev->right=*head;
        prev->rtag=1;
        (*head)->right=prev;
    }
}

void inOrder(threadNode* T)
{
    threadNode* curr=NULL;
    curr=T->left;
    while(curr!=T)
    {
        while(curr->ltag==0)
        {
            curr=curr->left;
        }
        printf("%c ",curr->data);
        while(curr->rtag==1&&curr->right!=T)
        {
            curr=curr->right;
            printf("%c ",curr->data);
        }
        curr=curr->right;
    }
    printf("\n");
}

int main()
{
    threadNode* head=NULL;
    threadNode* root=NULL;
    createTree(&root);
    inOrderThreading(&head,root);
    inOrder(head);
    return 0;
}
