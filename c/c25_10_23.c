#include <stdio.h>
#include <stdlib.h>

char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;

typedef struct treeNode
{
    struct treeNode* left;
    struct treeNode* right;
    char data;
}treeNode;

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

void preOrder(treeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    printf("%c ",T->data);
    preOrder(T->left);
    preOrder(T->right);
}

int test1()
{
    treeNode* root=NULL;
    createTree(&root);
    preOrder(root);
    return 0;
}

int main()
{
    test1();
    return 0;
}