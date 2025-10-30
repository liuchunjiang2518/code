#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

//定义一个结构体
typedef struct
{
    int *data;
    int length;
}list;

//内存地址初始化
list* initList()
{
    list *l=(list*)malloc(sizeof(list));
    l->data=(int*)malloc(sizeof(int)*maxsize);
    l->length=0;
    return l;
}

//在顺序表的尾部添加元素
int addElem(list *l,int n)
{
    if (l->length>=maxsize)
    {
        printf("顺序表已满\n");
        return 0;
    }
    l->data[(*l).length]=n;//两种写法
    l->length++;
    return 0;
}

//顺序表遍历
void listElem(list *l)
{
    printf("遍历顺序表：");
    for(int i=0;i<l->length;i++)
    {
        printf("%d ",l->data[i]);
    }
    printf("\n");
}

//顺序表中插入元素
int insertElem(list* l,int pos,int n)
{
    if(pos<=l->length)
    {
        for(int i=l->length;i>=pos;i--)
        {
            l->data[i]=l->data[i-1];
        }
        l->data[pos-1]=n;
        l->length++;
    }
    return 0;
}

//顺序表删除元素
int deleteElem(list* l,int pos,int *n)
{
    if(pos<=l->length)
    {
        *n=l->data[pos-1];
        for(int i=pos;i<l->length;i++)
        {
            l->data[i-1]=l->data[i];
        }
        l->length--;
    }
    return 0;
}

//顺序表查找元素的位置
int findElem(list* l,int n)
{
    for(int i=0;i<l->length;i++)
    {
        if(l->data[i]==n)
        {
            return i+1;
        }
    }
    return 0;
}

int main()
{
    list *myList;
    myList=initList();
    addElem(myList,13);
    addElem(myList,35);
    addElem(myList,27);
    addElem(myList,89);
    addElem(myList,91);
    listElem(myList);
    insertElem(myList,2,18);
    listElem(myList);
    int delData;
    deleteElem(myList,2,&delData);
    listElem(myList);
    printf("第%d个元素是27",findElem(myList,27));
    return 0;
}