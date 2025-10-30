#include <stdio.h>
#include <stdlib.h>
typedef int mytype;

typedef struct Node
{
    mytype data;
     struct Node* next;
}node;

int listNode(node* l)
{
    node* p=l->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}

int headInsert(node* l,mytype n)
{
    node* p=(node*) malloc (sizeof(node));
    p->data=n;
    p->next=l->next;
    l->next=p;
    return 0;
}

int freeNode(node* l)
{
    node* p=l;
    while(p->next!=NULL)
    {
        node* q=p->next;
        p=q->next;
        free(q);
    }
    free(l);
    return 0;
}

node* initNode()
{
    node* head=(node*) malloc (sizeof(node));
    head->data=0;
    head->next=NULL;
    return head;
}

int ifCircle(node* l)
{
    node* fast=l;
    node* slow=l;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (slow==fast)
            return 0;
    }
    return 1;
}

node* circleStart(node* l)
{
    int count=1;
    node* fast=l;
    node* slow=l;
    int circle=0;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if (slow==fast)
        {
            circle=1;
            break;
        }
    }
    if(circle==1)
    {
        print("是环");
        slow=slow->next;
        while(slow!=fast)
        {
            slow=slow->next;
            count++;
        }
        fast=l;
        slow=l;
        for(int i=0;i<count;i++)
        {
            fast=fast->next;
        }
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
    else
    {
        printf("不是环");
        return NULL;
    }
}



int main()
{
    node* head=initNode();
    headInsert(head,30);
    headInsert(head,20);
    headInsert(head,10);
    listNode(head);
    return 0;
}