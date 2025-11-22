//B树
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDER 3
#define MAX_KEY (ORDER-1)
#define MIN_KEY ((ORDER+1)/2-1)

typedef struct BTree
{
    int key_num;
    int keys[MAX_KEY];
    struct BTree* child[ORDER];
    bool is_leaf; 
}BTree;

BTree* root=NULL;

BTree* create_node(bool is_leaf)
{
    BTree* p=(BTree*)malloc(sizeof(BTree));
    
}