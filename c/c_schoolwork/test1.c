//实验一
//线性表基本运算算法设计
#include <stdlib.h>
#include <stdio.h>
#define maxsize 100

//顺序表
//创建顺序表结构体
typedef struct
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
    if(l->len>maxsize-1)
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
    printf("在位置%d加入了元素%d\n",pos,n);
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
    printf("在位置%d删除了元素%d\n",pos,l->data[pos-1]);
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
        printf("%d位置是%d\n",n,i+1);
        return i+1;
    }
    return 0;
}

//遍历元素
void traverseList(list* l)
{
    printf("遍历结果:");
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
    for(int i=0;i<5;i++)
    {
        insertElem(l,i,i*10);
    }
    traverseList(l);
    deleteElem(l,3);
    traverseList(l);
    selectElem(l,3);
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
    p->data=n;
    printf("在位置%d插入了元素%d\n",pos,p->data);
    p->next=q->next;
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
    node* p=q->next;
    q->next=p->next;
    printf("在位置%d删除了元素%d\n",pos,p->data);
    free(p);
    return 0;
}

//查找指定元素的位置
int selectNode(node* l,int n)
{
    node* p=l;
    int pos=0;
    while(p!=NULL)
    {
        p=p->next;
        pos++;
        if(p->data==n)
        {
            printf("%d的位置是%d\n",p->data,pos);
            return pos;
        }
    }
    return 0;
}

//遍历链表
void traverseNode(node* l)
{
    printf("遍历结果:");
    node* p=l->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//测试链表
int testNode()
{
    node* head=initNode();
    for(int i=0;i<5;i++)
    {
        insertNode(head,i,i*10);
    }   
    traverseNode(head);
    deleteNode(head,3);
    traverseNode(head);
    selectNode(head,40);
    insertNode(head,3,30);
    traverseNode(head);
    return 0;
}

int main()
{
    testList();
    testNode();
    return 0;
}