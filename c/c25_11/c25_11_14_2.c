#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//两数之和
//数组nums和整数target从nums找出两个数，它们的和是target,返回下标
//nums=[2,7,11,15],target=9;
//暴力求解
int* twoSums(int* nums,int size,int target)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                int* ret=malloc(sizeof(int)*2);
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
    }
    return NULL;
}

int testEnum()
{
    int nums[]={2,7,11,15};
    int target=26;
    int* ret=twoSums(nums,4,target);
    printf("(%d,%d)",ret[0],ret[1]);
    return 0;
}

int main()
{
    testEnum();
    return 0;
}

//哈希表

typedef struct hashNode
{
    int key; //数组元素值，作为哈希键
    int index; //元素对应的数组索引
    struct hashNode* next; //解决哈希冲突
}hashNode;

typedef struct hashTable
{
    int capacity;
    hashNode** table;
}hashTable;

hashNode* createHashNode(int key,int index)
{
    hashNode* p=(hashNode*)malloc(sizeof(hashNode));
    p->key=key;
    p->index=index;
    p->next=NULL;
    return p;
}

hashTable* createHashTable(int capacity)
{
    hashTable* H=(hashTable*)malloc(sizeof(hashTable));
    H->capacity=capacity;
    H->table=(hashNode**)calloc(capacity,sizeof(hashNode*));
    return H;
}

//计算键对应的数组下标
int hashFunc(int key,int capacity)
{
    return (key%capacity+capacity)%capacity;
}

//哈希表插入键值对
void hashInsert(hashTable* H,int key,int index)
{
    int idx=hashFunc(key,H->capacity);
    hashNode* p=createHashNode(key,index);
    p->next=H->table[idx];
    H->table[idx]=p;
}

int hashSearch(hashTable* H,int key)
{
    
}