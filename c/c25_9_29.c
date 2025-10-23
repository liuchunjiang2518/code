#include <stdio.h>
#include <stdlib.h>

//定义一个结构体
typedef struct Node
{
    int data;
    struct Node* next;
}node;

//初始化
node* initList()
{
    node* head=(node*) malloc (sizeof(node));
    head->data=0;
    head->next=NULL;
    return head;
}

//头插法
int insertHead(node* li,int n)
{
    node* p=(node*) malloc (sizeof(node));
    p->data=n;
    p->next=li->next;
    li->next=p;
    return 0;
}

//遍历
void listNode(node* li)
{
    node* p=li->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//获取链表尾部
node* findTail(node* li)
{
    node* p=li;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}

//尾插法
node* insertTail(node* tail,int n)
{
    node* p=(node*) malloc (sizeof(node));
    p->data=n;
    p->next=NULL;
    tail->next=p;
    return p;
}

//指定位置插入
int insertNode(node* li,int pos,int n)
{
   node* p=(node*) malloc (sizeof(node));
   node* q=li;
   for(int i=0;i<pos-1;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            return 0;
        }
    }
   p->data=n;
   p->next=q->next;
   q->next=p;
   return 1;
}

//删除指定位置元素
int delNode(node* li,int pos)
{
    node* p=li;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
        if(p==NULL)
        {
            return 0;
        }
    }
    if(p->next==NULL)
    {
        printf("error");
        return 0;
    }
    node* q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}

int main()
{
    node* li=initList();
    insertHead(li,30);
    insertHead(li,20);
    insertHead(li,10);
    node* tail=findTail(li);
    tail=insertTail(tail,40);
    tail=insertTail(tail,50);
    insertNode(li,3,25);
    listNode(li);
    delNode(li,6);
    listNode(li);
    return 0;
}