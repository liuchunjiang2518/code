//哈希函数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 5

typedef struct
{
    int num;
    char* data;
}hashTable;

hashTable* initHashTable()
{
    hashTable* H=(hashTable*)malloc(sizeof(hashTable));
    H->num=0;
    H->data=(char*)malloc(sizeof(char)*NUM);
    for(int i=0;i<NUM;i++)
    {
        H->data[i]=0;
    }
    return H;
}

int hashMod(char data)
{
    return (unsigned char)data%NUM;
}

void putHash(hashTable* H,char data)
{
    int idx=hashMod(data);
    //解决冲突
    while(H->data[idx]!=0)
    {
        idx=(idx+1)%NUM;
    }
    H->data[idx]=data;
    H->num++;
}

int main()
{
    hashTable* H=initHashTable();
    putHash(H,'A');
    putHash(H,'F');
    for(int i=0;i<NUM;i++)
    {
        printf("%c ",H->data[i]);
    }
    return 0;
}