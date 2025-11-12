//实验九
//查找算法设计
#include <stdio.h>
#include <stdlib.h>

//顺序查找
int seqSearch(int* arr,int len,int n)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==n)
        {
            return i;
        }
    }
    return -1;
}

//二分查找
int binarySearch(int* arr,int len,int n)
{
    int low=0;
    int high=len-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>n)
        {
            high=mid-1;
        }
        else if(arr[mid]<n)
        {
            low=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

//二叉排序树

int arrTree[]={70,55,49,30,-1,39,-1,-1,53,-1,-1,-1,80,75,-1,-1,98,95,-1,-1,-1};
int idx=0;

typedef struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

void createTree(treeNode** T)
{
    int num=arrTree[idx++];
    if(num==-1)
    {
        *T=NULL;
        return;
    }
    else
    {
        *T=(treeNode*)malloc(sizeof(treeNode));
        (*T)->data=num;
        createTree(&(*T)->left);
        createTree(&(*T)->right);
    }
}

void preOrderTraverse(treeNode* T)
{
    if(T==NULL)
    {
        return;
    }
    printf("%d ",T->data);
    preOrderTraverse(T->left);
    preOrderTraverse(T->right);
};

int bstSearch(treeNode* T,int n,treeNode* parent,treeNode** pos)
{
    if(T==NULL)
    {
        *pos=parent;
        return 1;
    }
    if(T->data==n)
    {
        *pos=T;
        return 0;
    }
    if(T->data>n)
    {
        bstSearch(T->left,n,parent,pos);
    }
    if(T->data<n)
    {
        bstSearch(T->right,n,parent,pos);
    }
}

int test_bstSearch()
{
    treeNode* T=NULL;
    treeNode* P=NULL;
    createTree(&T);
    preOrderTraverse(T);
    printf("\n");
    bstSearch(T,80,NULL,&P);
    printf("%d ",P->data);
    return 0;
}

int main()
{
    test_bstSearch();
    return 0;
}