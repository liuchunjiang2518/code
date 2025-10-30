#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int mytype;

typedef struct 
{
    mytype* data;
    int top;
}stack;

typedef enum
{
    LEFT_PARE,RIGHT_PARE,
    ADD,SUB,MUL,DIV,MOD,
    EOS,NUM
}contentType;

stack* initStack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->data=(mytype*)malloc(sizeof(mytype)*maxsize);
    s->top=-1;
    return s;
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

int pop(stack* s,mytype* deldata)
{
    if(s->top==-1)
    {
        return 1;
    }
    *deldata=s->data[s->top];
    s->top--;
    return 0;
}

contentType getToken(char* symbol,int* index)
{
    char expr[]="82/2+56*-";
    *symbol=expr[*index];
    (*index)++;
    switch(*symbol)
    {
        case '(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '\0':
            return EOS;
        default:
            return NUM;
        }
}

int eval(stack* s)
{
    mytype result=0;
    mytype op1,op2;
    char symbol;
    int index=0;
    contentType token=getToken(&symbol,&index);
    while(token!=EOS)
    {
        if(token==NUM)
        {
            push(s,symbol-'0');
        }
        else
        {
            pop(s,&op1);
            pop(s,&op2);
            switch(token)
            {
                case ADD:
                    push(s,op2+op1);
                    break;
                case SUB:
                    push(s,op2-op1);
                    break;
                case MUL:
                    push(s,op2*op1);
                    break;
                case DIV:
                    push(s,op2/op1);
                    break;
                case MOD:
                    push(s,op2%op1);
                    break;
                default:
                    break;
                }
        }
        token=getToken(&symbol,&index);
    }
    pop(s,&result);
    printf("%d",result);
    return 0;
}

int main()
{
    stack* s=initStack();
    eval(s);
    return 0;
}