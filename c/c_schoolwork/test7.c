//实验七二
//用二叉树表示家谱并实现相关算法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 家族成员节点结构
typedef struct familyNode
{
    char name[20];
    char gender[5];
    char birth[20];
    struct familyNode *child;
    struct familyNode *sibling;
}familyNode;

//创建新成员
familyNode* createNode(char* name,char* gender,char* birth)
{
    familyNode *newNode=(familyNode*)malloc(sizeof(familyNode));
    if(newNode==NULL)
    {
        printf("内存分配失败!");
        exit(1);
    }
    strcpy(newNode->name,name);
    strcpy(newNode->gender,gender);
    strcpy(newNode->birth,birth);
    newNode->child=NULL;
    newNode->sibling=NULL;
    return newNode;
}

//前序遍历家谱
void preOrderTraverse(familyNode* root,int dep)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<dep;i++)
    {
        printf("  ");
    }
    printf("%s(%s,%s)\n",root->name,root->gender,root->birth);
    preOrderTraverse(root->child,dep+1);
    preOrderTraverse(root->sibling,dep);
}

//查找指定姓名的成员
familyNode* findMember(familyNode* root,char* targetName)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(strcmp(root->name,targetName)==0)
    {
        return root;
    }
    familyNode* foundInChild=findMember(root->child,targetName);
    if(foundInChild!=NULL)
    {
        return foundInChild;
    }
    return findMember(root->sibling,targetName);
}

//为指定成员添加子女
int addChild(familyNode* parent,char* childName,char* gender,char* birth)
{
    if(parent==NULL)
    {
        printf("父/母成员不存在，添加失败!\n");
        return 0;
    }
    familyNode* newChild=createNode(childName,gender,birth);
    if(parent->child==NULL)
    {
        parent->child=newChild;
    }
    else
    {
        familyNode* lastChild=parent->child;
        while(lastChild->sibling!=NULL)
        {
            lastChild=lastChild->sibling;
        }
        lastChild->sibling=newChild;
    }
    printf("成功为%s添加子女:%s\n",parent->name,childName);
    return 1;
}

//统计家族总人数
int countFamilyMembers(familyNode* root)
{
    if(root==NULL)
    {
        return 0;
    }    
    return 1+countFamilyMembers(root->child)+countFamilyMembers(root->sibling);
}

//释放家谱内存
void freeFamilyTree(familyNode* root)
{
    if(root==NULL)
    {
        return;
    }
    freeFamilyTree(root->child);
    freeFamilyTree(root->sibling);
    free(root);
}

//菜单交互
int main()
{
    familyNode* root=NULL;
    int choice;
    char name[20],gender[5],birth[20],parentName[20];
    while(1)
    {
        printf("\n===== 家谱管理系统 =====\n");
        printf("1. 创建家谱根节点(祖先)\n");
        printf("2. 前序遍历显示家谱\n");
        printf("3. 查找家族成员\n");
        printf("4. 为成员添加子女\n");
        printf("5. 统计家族总人数\n");
        printf("0. 退出系统\n");
        printf("请输入操作编号:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
                if (root!=NULL)
                {
                    printf("家谱已存在根节点,无需重复创建！\n");
                    break;
                }
                printf("请输入根节点信息:\n");
                printf("姓名:");
                scanf("%s",name);
                printf("性别(男/女):");
                scanf("%s",gender);
                printf("出生日期(YYYY-MM-DD):");
                scanf("%s",birth);
                root=createNode(name,gender,birth);
                printf("成功创建家谱根节点:%s\n",name);
                break;
            case 2:
                if(root==NULL)
                {
                    printf("家谱为空,请先创建根节点!\n");
                    break;
                }
                printf("\n===== 家谱结构(前序遍历)=====\n");
                preOrderTraverse(root, 0);
                break;
            case 3:
                if(root==NULL)
                {
                    printf("家谱为空,请先创建根节点!\n");
                    break;
                }
                printf("请输入要查找的成员姓名:");
                scanf("%s",name);
                familyNode* found=findMember(root,name);
                if(found!=NULL)
                {
                    printf("找到成员:%s(%s,%s)\n",found->name,found->gender,found->birth);
                }
                else
                {
                    printf("未找到成员:%s\n",name);
                }
                break;
            case 4:
                if(root==NULL)
                {
                    printf("家谱为空,请先创建根节点!\n");
                    break;
                }
                printf("请输入父/母成员姓名:");
                scanf("%s",parentName);
                familyNode* parent=findMember(root,parentName);
                if(parent==NULL)
                {
                    printf("未找到父/母成员:%s\n",parentName);
                    break;
                }
                printf("请输入子女信息:\n");
                printf("姓名:");
                scanf("%s",name);
                printf("性别(男/女):");
                scanf("%s",gender);
                printf("出生日期(YYYY-MM-DD):");
                scanf("%s",birth);
                addChild(parent,name,gender,birth);
                break;
            case 5:
                if(root==NULL)
                {
                    printf("家谱为空,人数为0!\n");
                    break;
                }
                printf("家族总人数:%d\n",countFamilyMembers(root));
                break;
            case 0:
                printf("退出系统,释放内存...\n");
                freeFamilyTree(root);
                root=NULL;
                printf("退出成功!\n");
                return 0;
            default:
                printf("输入错误,请重新输入操作编号!\n");
                break;
        }
    }
}