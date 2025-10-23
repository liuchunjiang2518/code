#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;

typedef struct TreeNode 
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}treeNode;

typedef struct 
{
    treeNode** data;
    int top;
}stack;

stack* initStack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->data=(treeNode*)malloc(sizeof(treeNode)*maxsize);
    s->top=-1;
    return s;
}

void push(stack* s,treeNode* T)
{
    s->data[++s->top]=T;
}

treeNode* pop(stack* s)
{
    return s->data[s->top--];
}

int isEmpty(stack* s)
{
    return s->top==-1;
}

//非递归方法遍历
void iterPreOrde(treeNode* T)
{
    stack* s=initStack();
    
}

//递归方法，前序遍历  postOrder,inOrder
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

//原因：main中，先treeNode* root=NULL;要修改root的指针必须用到二级指针
void createTree(treeNode** T)
{
    char ch;
    ch=str[idx++];
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

int main()
{
    treeNode* root=NULL;
    createTree(&root);
    preOrder(root);
    return 0;
}