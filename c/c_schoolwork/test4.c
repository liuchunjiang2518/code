//实验四
//串的模式匹配算法设计
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100

//串的顺序结构
typedef struct
{
    char ch[maxsize];
    int lenth;
}string;

//初始化串
void initString(string* s,char* str)
{
    int len=strlen(str);
    if(len>=maxsize)
    {
        s->lenth=0;
        return;
    }
    for(int i=0;i<len;i++)
    {
        s->ch[i]=str[i];
    }
    s->ch[len]='\0';
    s->lenth=len;
}

//打印串的内容,长度
void printString(string* s)
{
    printf("串内容:%s,串长度:%d",s->ch,s->lenth);
}

//BF算法
int BFMatch(string* T,string* P)
{
    int i=0;
    int j=0;
    if(P->lenth==0||T->lenth<P->lenth)
    {
        printf("匹配失败:模式串为空或模式串大于主串");
        return -1;
    }
    while(i<T->lenth&&j<P->lenth)
    {
        if(T->ch[i]==P->ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j==P->lenth)
    {
        printf("匹配成功,位置为%d",i-j);
        return i-j;
    }
    else
    {
        printf("匹配失败:无匹配项");
        return -2;
    }
}

int main()
{
    string* T=(string*)malloc(sizeof(string));
    string* P=(string*)malloc(sizeof(string));
    initString(T,"ABCABDABCABC");
    initString(P,"ABCABC");
    printString(T);
    printString(P);
    BFMatch(T,P);
    return 0;
}