#include <stdio.h>
#include <stdlib.h>

typedef struct threadNode
{
    char data;
    struct threadNode* right;
    struct threadNode* left;
    int rtag;
    int ltag;
}threadNode;

threadNode* prev=NULL;
char str[]="ABDH##I##EJ###CF##G##";
int idx=0;

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

void inThreading(threadNode* T)
{
    if(T!=NULL)
    {
        inThreading(T->left);
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
        inThreading(T->right);
    }
}

void inOrderThreading(threadNode** head,threadNode* T)
{
    *head=(threadNode*)malloc(sizeof(threadNode));
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->right=*head;
    if(T==NULL)
    {
        (*head)->left=*head;
    }
    else
    {
        (*head)->left=T;
        prev=*head;
        inThreading(T);
        prev->right=*head;
        prev->rtag=1;
        (*head)->right=prev;
    }
}

void inOrderTraverse(threadNode* T)
{
    threadNode* curr=T->left;
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

void preThreading(threadNode* T)
{
    if(T!=NULL)
    {
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
        if(T->ltag==0)
        {
            preThreading(T->left);
        }
        if(T->rtag==0)
        {
            preThreading(T->right);
        }    
    }
}

void preOrderThreading(threadNode** head,threadNode* T)
{
    *head=(threadNode*)malloc(sizeof(threadNode));
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->right=*head;
    if(T==NULL)
    {
        (*head)->left=*head;
    }
    else
    {
        (*head)->left=T;
        prev=*head;
        preThreading(T);
        prev->right=*head;
        prev->rtag=1;
        (*head)->right=prev;
    }
}

void preOrderTraverse(threadNode* T)
{
    threadNode* curr=T->left;
    while(curr!=T)
    {
        printf("%c ",curr->data);
        if(curr->ltag==0)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    printf("\n");
}

int testInOrder()
{
    threadNode* head=NULL;
    threadNode* root=NULL;
    createTree(&root);
    inOrderThreading(&head,root);
    inOrderTraverse(head);
    idx=0;
    return 0;
}

int testPreOrder()
{
    threadNode* head=NULL;
    threadNode* root=NULL;
    createTree(&root);
    preOrderThreading(&head,root);
    preOrderTraverse(head);
    idx=0;
    return 0;
}

int main()
{
    testInOrder();
    testPreOrder();
    return 0;
}