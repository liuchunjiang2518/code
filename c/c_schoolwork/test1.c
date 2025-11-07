//实验一
//线性表基本运算算法设计

#include <stdlib.h>
#include <stdio.h>
//顺序表
#define maxsize 100

//创建顺序表结构体
typedef struct list
{
    int* data;
    int len;
}list;

//初始化
list* initList()
{
    list* l=(list*)malloc(sizeof(list));
    l->data=(int*)malloc(sizeof(int)*maxsize);
    l->len=0;
    return l;
}

//指定位置插入元素
int insertElem(list* l,int pos,int n)
{
    if(l->len>=maxsize)
    {
        return 2;
    }
    if(pos<1||pos>l->len+1)
    {
        return 1;
    }
    for(int i=l->len;i>=pos;i--)
    {
        l->data[i]=l->data[i-1];
    }
    l->data[pos-1]=n;
    l->len++;
    return 0;
}

//指定位置删除元素
int deleteElem(list* l,int pos)
{
    if(l->len==0)
    {
        return 2;
    }
    if(pos<1||pos>l->len)
    {
        return 1;
    }
    for(int i=pos;i<l->len;i++)
    {
        l->data[i-1]=l->data[i];
    }
    l->len--;
    return 0;
}

//查找元素位置
int selectElem(list* l,int n)
{
    for(int i=0;i<l->len;i++)
    {
        if(l->data[i]==n)
        return i+1;
    }
    return 0;
}

//遍历元素
void traverseList(list* l)
{
    for(int i=0;i<l->len;i++)
    {
        printf("%d ",l->data[i]);
    }
    printf("\n");
}

//测试顺序表
int testList()
{
    list* l=initList();
    insertElem(l,1,10);
    insertElem(l,2,20);
    insertElem(l,3,30);
    insertElem(l,4,40);    
    insertElem(l,5,50);
    traverseList(l);
    deleteElem(l,3);
    printf("20位置是%d\n",selectElem(l,20));
    traverseList(l);
    insertElem(l,3,30);
    traverseList(l);
    return 0;
}

//链表

//创建链表结构体
typedef struct node
{
    int data;
    struct node* next;
}node;

//初始化
node* initNode()
{
    node* l=(node*)malloc(sizeof(node));
    l->next=NULL;
    l->data=0;
    return l;
}

//插入结点
int insertNode(node* l,int pos,int n)
{
    node* p=(node*)malloc(sizeof(node));
    node* q=l;
    for(int i=0;i<pos-1;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            return 1;
        }
    }
    p->next=q->next;
    p->data=n;
    q->next=p;
    return 0;
}

//删除结点
int deleteNode(node* l,int pos)
{
    node* q=l;
    for(int i=0;i<pos-1;i++)
    {
        q=q->next;
        if(q->next==NULL)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    testList();
    return 0;
}