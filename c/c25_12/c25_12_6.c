#include <stdio.h>
#include <stdlib.h>

int search(int* data,int len,int val)
{
    for(int i = 0;i < len;i++)
    {
        if(data[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int* data,int len,int val)
{
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(val < data[mid])
        {
            high = mid - 1;
        }
        else if(val > data[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int arr[] = {70, 55, 49, 30, -1, 39, -1, -1, 53, -1, -1, -1, 80, 75, -1, -1, 98, 95, -1, -1, -1};
int arr2[] = {70, 55, 49, 30, 39, 53, 80, 75, 98, 95};
int idx = 0;

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

void createTree(TreeNode** T)
{
    int num = arr[idx++];
    if(num == -1)
    {
        *T = NULL;
        return;
    }
    *T = (TreeNode*)malloc(sizeof(TreeNode));
    (*T)->data = num;
    createTree(&(*T)->left);
    createTree(&(*T)->right); 
}

int BST(TreeNode* T,int val,TreeNode* par,TreeNode** pos)
{
    if(T == NULL)
    {
        *pos = par;
        return 1;
    }
    if(T->data == val)
    {
        *pos = T;
        return 0;
    }
    if(T->data > val)
    {
        return BST(T->left,val,T,pos);
    }
    else
    {
        return BST(T->right,val,T,pos);
    }
}

int insertBST(TreeNode** T,int val)
{
    TreeNode* par = NULL;
    TreeNode* pos = NULL;
    TreeNode* curr = NULL;
    int status = BST(*T,val,NULL,&pos);
    if(status == 1)
    {
        curr = (TreeNode*)malloc(sizeof(TreeNode));
        curr->data = val;
        curr->left = NULL;
        curr->right = NULL;
        if(pos == NULL)
        {
            *T = curr;
        }
        else if(pos->data < val)
        {
            pos->right = curr;
        }
        else
        {
            pos->left = curr;
        }
        return 0;
    }
    return 1;
}

int delete(TreeNode** del)
{
    TreeNode* temp = NULL;
    TreeNode* record = NULL;
    if((*del)->right == NULL)
    {
        temp = *del;
        *del = (*del)->left;
        free(temp);
    }
    else if((*del)->left == NULL)
    {
        temp = *del;
        *del = (*del)->right;
        free(temp);
    }
    else
    {
        temp = *del;
        record = (*del)->left;
        while(record->right != NULL)
        {
            temp = record;
            record = record->right;
        }
        (*del)->data = record->data;
        if(temp != *del)
        {
            temp->right = record->left;
        }
        else
        {
            temp->left = record->left;
        }
        free(record);
    }
}

int deleteBST(TreeNode** T,int val)
{
    if(T == NULL || *T == NULL)
    {
        printf("not found!");
        return 1;
    }
    else
    {
        if((*T)->data == val)
        {
            return delete(T);
        }
        else if((*T)->data > val)
        {
            return deleteBST(&(*T)->left,val);
        }
        else
        {
            return deleteBST(&(*T)->right,val);
        }
    }
}

void preOrderTraverse(TreeNode* T)
{
    if(T == NULL)
    {
        return;
    }
    printf("%d ",T->data);
    preOrderTraverse(T->left);
    preOrderTraverse(T->right);
}

int test1()
{
    int arr[] = {15,2,8,9,3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int pos = search(arr,len,8);
    printf("%d ",pos);
    return 0;
}

int test2()
{
    int arr[] = {2,4,8,9,13,19};
    int len = sizeof(arr) / sizeof(arr[0]);
    int pos = binarySearch(arr,len,13);
    printf("%d ",pos);
    return 0;
}

int test3()
{
    TreeNode* T = NULL;
    TreeNode* pos = NULL;
    createTree(&T);
    BST(T,53,NULL,&pos);
    printf("%d ",pos->data);
    idx = 0;
    return 0;
}

int test4()
{
    int len = sizeof(arr2) / sizeof(arr2[0]);
    TreeNode* T = NULL;
    for(int i = 0;i < len;i++)
    {
        insertBST(&T,arr2[i]);
    }
    printf("\n");
    preOrderTraverse(T);
    return 0;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}