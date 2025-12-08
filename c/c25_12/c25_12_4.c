#include <stdio.h>
#include <stdlib.h>

int idx = 0;
char str[] = "ABDH#K###E##CFI###G#J##";

typedef struct TreeNode
{
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

void createTree(TreeNode** T)
{
    char ch = str[idx ++];
    if(ch == '#')
    {
        (*T) = NULL;
        return;
    }
    *T = (TreeNode*)malloc(sizeof(TreeNode));
    (*T)->data = ch;
    createTree(&(*T)->left);
    createTree(&(*T)->right);
}

void preOrderTraverse(TreeNode* T)
{
    if(T == NULL)
    {
        return;
    }
    printf("%c ",T->data);
    preOrderTraverse(T->left);
    preOrderTraverse(T->right);
}

int main()
{
    TreeNode* root = NULL;
    createTree(&root);
    preOrderTraverse(root);
    return 0;
}