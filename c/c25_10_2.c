#include <stdio.h>
#include <stdlib.h>

//复习一遍链表
typedef struct Node
{
    int data;
    struct Node* next;
}node;

node* initNode()
{
    node* head=(node*) malloc (sizeof(node));
    head->data=0;
    head->next=NULL;
    return head;
}

void headInsert(node* l,int n)
{
    node* p=(node*) malloc (sizeof(node));
    p->data=n;
    p->next=l->next;
    l->next=p;
}

void listNode(node* l)
{
    node* p=l->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

node* findTail(node* l)
{
    node* p=l;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}

node* nodeInsert(node* tail,int n)
{
    node* p=(node*) malloc (sizeof(node));
    p->data=n;
    p->next=tail->next;
    tail->next=p;
    return p;
}

int insertNode(node* l,int pos,int n)
{
    node* p=(node*) malloc (sizeof(node));
    p->data=n;
    node* q=l;
    for(int i=0;i<pos-1;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            return 0;
        }
    }
    p->next=q->next;
    q->next=p;
    return 0;
}

int delNode(node* l,int pos)
{
    node* p=l;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    if(p->next==NULL)
    {
        printf("error");
    }
    node* q=p->next;
    p->next=q->next;
    free(q);
    return 0;
}

int delAllNode(node* l)//不删头节点
{
    node* p=l->next;
    while(p!=NULL)
    {
        node* q=p;
        p=p->next;
        free(q);
    }
    return 0;
}

//找到倒数第n个数
int findNodeFS(node* l,int n)
{
    node* fast=l;
    node* slow=l;
    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    printf("倒数第%d个数是%d",n,slow->data);
    return 0;
}

int lengthNode(node* l)
{
    node* p=l->next;
    int len=0;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

//找到相同后缀起始位置loading being node->data 的数据类型为char str2较大
node* test(node* str1,node* str2)
{
    int len=lengthNode(str2)-lengthNode(str1);
    node* fast=str2->next;
    node* slow=str1->next;
    for(int i=0;i<len;i++)
    {
        fast=fast->next;
    }
    while(fast!=slow)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}



int main()
{
    node* head=initNode();
    return 0;
}