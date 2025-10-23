#include <stdio.h>
#include <stdlib.h>

typedef int mytype;

typedef struct Node
{
    mytype data;
    struct Node *prev,*next; 
}node;

void headInsert(node* l,mytype n)
{
    node* p=(node*)malloc(sizeof(node));
    p->data=n;
    p->prev=l;
    p->next=l->next;
    if (l->next!=NULL)
    {
        l->next->prev=p;
    }
    l->next=p;
}

node* tailInsert(node* tail,mytype n)
{
    node* p=(node*)malloc(sizeof(node)); 
    p->prev=tail;
    p->next=tail->next;
    tail->next=p;
    p->data=n;
    return p;
}

int insertNode(node* l,int pos,mytype n)
{
    if(l==NULL)
    return 1;
    int len =0;
    node* plen=l;
    while(plen!=NULL)
    {
        len++;
        plen=plen->next;
    }
    if(pos<1||pos>len+1)
    {
        return 2;
    }
    node* p=(node*)malloc(sizeof(node));
    node* q=l;
    for(int i=0;i<pos-1;i++)
    {
        q=q->next;
        //if(p==NULL)
        //{
        //  return 2;
        //}        
    }
    p->prev=q;
    p->next=q->next;
    q->next->prev=p;
    q->next=p;
    return 0;
}

int deleteNode(node* l,int pos)
{
    node* p=l;
    if(l==NULL)
    return 1;
    int len =0;
    node* plen=l;
    while(plen!=NULL)
    {
        len++;
        plen=plen->next;
    }
    if(pos<1||pos>len+1)
    {
        return 2;
    }
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    node* q=p->next;
    if(q->next!=NULL)
    {
        q->next->prev=p;
    }
    p->next=q->next;
    free(q);
    return 0;
}

node* findTail(node* l)
{
    node* p=l;
    if(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}


//栈与列表
#define maxsize 100
typedef struct 
{
    mytype data[maxsize];
    int top;
}stack;

void initStack(stack* s)
{
    s->top=-1;
}

int ifEmpty(stack* s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(stack* s,mytype n)
{
    if(s->top>=maxsize-1)
    {
        return 1;
    }
    s->top++;
    s->data[s->top]=n;
    return 0;
}

mytype* pop(stack* s,mytype* n)
{
    if(s->top==-1)
    {
        return NULL;
    }
    *n=s->data[s->top];
    s->top--;
    return n;
}

void listStack(stack* s)
{
    // while(s->top!=-1)
    // {
    //     printf("%d ",s->data[s->top]);    
    //     s->top--;
    // }
    for(int i=0;i<s->top+1;i++)
    {
        printf("%d ",s->data[i]);
    }
}

int main()
{
    stack* s=(stack*)malloc(sizeof(stack));
    initStack(s);
    push(s,24);
    push(s,12);
    push(s,13);
    push(s,38);
    mytype* deldata=pop(s,deldata);
    listStack(s);
    printf("\n%d",*deldata);
    return 0;
}

