#include <stdio.h>
#include<stdlib.h>
#include"Node.h"

void insert(treePointer root, treePointer target)
{
	if (target->value == root->value) {
		printf("Error!\n");
		printf("Including the same number!!\n");
		system("pause");
		exit(1);
	}
	else if (target->value < root->value) {
		if (root->left_node == NULL)
			root->left_node = target;
		else
			insert(root->left_node, target);
	}
	else {
		if (root->right_node == NULL)
			root->right_node = target;
		else
			insert(root->right_node, target);
	}
}

treePointer search(treePointer root, int NODE)
{
	if (!root) return NULL;
	if (NODE == root->value) return root;
	if (NODE < root->value)
		return search(root->left_node, NODE);
	return search(root->right_node, NODE);
}

void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->left_node);
		ptr->pos = position++;
		printf("% 2d", ptr->value);
		inorder(ptr->right_node);
	}
}

void delinorde(treePointer ptr, int num)
{
	if (ptr) {
		delinorde(ptr->left_node, num);
		if (ptr->pos != num)
			printf("% 2d", ptr->value);
		delinorde(ptr->right_node, num);
	}
}