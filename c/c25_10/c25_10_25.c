#include <stdio.h>
#include <stdlib.h>

char str[]="ABDH##I##EJ###CF##G##";
int idx=0;

typedef struct treeNode
{
    char data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

void createTree(treeNode** T)
{
    char ch=str[idx++];
    if(ch=='#')
    {
        *T=NULL;
    }
    else
    {
        *T=(treeNode*)malloc(sizeof(treeNode));
        (*T)->data=ch;
        createTree(&(*T)->left);
        createTree(&(*T)->right);
    }
}

void preOrder(treeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    else
    {
        printf("%c ",T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

int main()
{
    treeNode* root=NULL;
    createTree(&root);
    preOrder(root);
    return 0;
}