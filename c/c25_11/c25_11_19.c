#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

int idx=0;
char str[]="ABDH#K###E##CFI###G#J##";

void createTree(TreeNode** T)
{
    int ch=str[idx++];
    if(ch=='#')
    {
        *T=NULL;
        return;
    }
    else
    {
        *T=(TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        createTree(&(*T)->left);
        createTree(&(*T)->right);
    }
}

void preOrderTraverse(TreeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    else
    {
        printf("%c ",T->data);
        preOrderTraverse(T->left);
        preOrderTraverse(T->right);
    }
}

int main()
{
    TreeNode* T=NULL;
    createTree(&T);
    preOrderTraverse(T);
    return 0;
}