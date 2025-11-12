//哈希查找
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hash_size 10

typedef struct hashNode
{
    int key;
    struct hashNode* next;
}hashNode;

typedef struct hashTable
{
    hashNode* table[hash_size];
}hashTable;

//取模
static int hashFunc(int key)
{
    return key%hash_size;
}

hashTable* initHashTable()
{
    hashTable* H=(hashTable*)malloc(sizeof(hashTable));
    for(int i=0;i<hash_size;i++)
    {
        H->table[i]=NULL;
    }
    return H;
}

void insertHash(hashTable* H,int key)
{
    int idx=hashFunc(key);
    hashNode* p=(hashNode*)malloc(sizeof(hashNode));
    p->key=key;
    p->next=NULL;
    if(H->table[idx]==NULL)
    {
        H->table[idx]=p;
    }
    else
    {
        p->next=H->table[idx];
        H->table[idx]=p;
    }
}

hashNode* searchHash(hashTable* H,int target)
 {
    int idx=hashFunc(target); 
    hashNode* p=H->table[idx];
    while(p!=NULL)
    {
        if(p->key==target) 
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main()
{
    hashTable* H=initHashTable(H);
    int data[]={12,22,32,45,55,65,78,88};
    int len=sizeof(data)/sizeof(data[0]);
    for(int i=0;i<len;i++)
    {
        insertHash(H,data[i]);
    }
    int target=45;
    hashNode* P=searchHash(H,target);
    for(int i=0;i<len;i++)
    { 
        printf("%d ",data[i]);
    }
    printf("\n查找目标:%d → %s\n",target,P!= NULL?"找到":"未找到");
    return 0;
}