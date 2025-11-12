//实验六
//二叉树的算法设计
#include <stdio.h>
#include <stdlib.h>
char str[]="ABDH##I##EJ###CF##G##";
int idx=0;

//二叉树结构体
typedef struct treeNode
{
    struct treeNode* left;
    struct treeNode* right;
    char data;
}treeNode;

//初始化二叉树
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

//先序遍历
void preOrderTraverse(treeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    printf("%c ",T->data);
    preOrderTraverse(T->left);
    preOrderTraverse(T->right);
}

//中序遍历
void inOrderTraverse(treeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    inOrderTraverse(T->left);
    printf("%c ",T->data);
    inOrderTraverse(T->right);
}

//后序遍历
void postOrderTraverse(treeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    postOrderTraverse(T->left);
    postOrderTraverse(T->right);
    printf("%c ",T->data);
}

int main()
{
    treeNode* root=NULL;
    createTree(&root);
    preOrderTraverse(root);
    printf("\n");
    inOrderTraverse(root);
    printf("\n");
    postOrderTraverse(root);
    printf("\n");
    return 0;
}