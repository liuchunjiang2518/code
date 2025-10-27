#include <stdio.h>
#include <stdlib.h>

typedef struct threadNode
{
    char data;
    struct threadNode* left;
    struct threadNode* right;
    int ltag,rtag;
}threadNode;

threadNode* prev=NULL;
char str[]="ABDH##I##EJ###CF##G##";
int idx=0;

void createTree(threadNode** T)
{
    char ch=str[idx++];
    if(ch=='#')
    {
        *T=NULL;
        return;
    }
    
}