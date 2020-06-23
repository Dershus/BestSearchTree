#include <stdio.h>
#include <stdlib.h>

#define MALLOC(pos,size)\
        if(!((pos) = (treePointer)malloc(size))) {\
        printf("Insufficient memory");\
        exit(0);\
        }
static int position = 1;

typedef struct node *treePointer;
typedef struct node {
	treePointer left_node;
	int value;
	treePointer right_node;
	int pos = 0;
};

void insert(treePointer root, treePointer target);
treePointer search(treePointer root, int NODE);
void inorder(treePointer ptr);
void delinorde(treePointer ptr, int num);