#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include "Node.h"

int main(){
	FILE *inp;
	int states, num, find;
	treePointer NODE[100];
	treePointer temp;
	
	char filename[20] = { "\0" };
	printf("Please enter which file be the input : ");
	scanf("%s", &filename);
	strcat(filename, ".txt");

	printf("==================================\n");
	printf("You select the file : %s\n", filename);

	if (!(inp = fopen(filename, "r"))) {
		printf("==================================\n");
		printf("Error Enter !!! There is not a file named %s \n",filename);
		printf("==================================\n");
		system("pause");
		exit(0);
	}

	fscanf(inp, "%d", &num);					/*select the root*/
	MALLOC(NODE[0], sizeof(*NODE[0]));			/*declare a dynamical node*/
	NODE[0]->left_node = NULL;					/*set the node's left and right child's pointer*/
	NODE[0]->right_node = NULL;
	NODE[0]->value = num;						/*set the value*/
	
	int node_num = 1;
	while (fscanf(inp, "%d", &num) != EOF) {				/*set the binary search tree*/
		MALLOC(NODE[node_num], sizeof(*NODE[node_num]));
		NODE[node_num]->left_node = NULL;
		NODE[node_num]->right_node = NULL;
		NODE[node_num]->value = num;
		insert(NODE[0], NODE[node_num]);
		node_num++;
	}

	printf("Inorder:");
	inorder(NODE[0]);
	printf("\n\n");
	do {
		printf("==================================\n");
		printf("1.Insert a node\n");
		printf("2.Delete a node\n");
		printf("3.Find a node\n");
		printf("4.Quit\n");
		printf("==================================\n");
		printf("Choose a function : ");
		scanf("%d", &states);
		printf("\n\n\n==================================\n");
		switch (states) {
		case 1:
			printf("Enter a number : ");
			scanf("%d", &find);

			MALLOC(temp, sizeof(*temp));
			temp->left_node = NULL;
			temp->right_node = NULL;
			temp->value = find;
			insert(NODE[0], temp);
			printf("Inorder:");
			inorder(NODE[0]);
			printf("\n==================================\n");
			break;
		case 2:
			printf("Enter the node=> ");
			scanf("%d", &find);
			if (search(NODE[0], find)) {
				printf("Inorder: ");
				delinorde(NODE[0], search(NODE[0], find)->pos);
				printf("\n==================================\n");
			}
			else {
				printf("Error!\n");
				printf("The node is not exist!!\n");
				printf("==================================\n");
			}
			break;
		case 3:
			printf("Enter the node=> ");
			scanf("%d", &find);
			if (search(NODE[0], find)) {
				printf("The node's position is %d.\n", search(NODE[0], find)->pos);
				printf("==================================\n");
			}
			else {
				printf("Error enter!\n");
				printf("The node is not exist!!\n");
				printf("==================================\n");
			}
			break;
		case 4:
			printf("Quit the program\n");
			printf("==================================\n");
			break;
		default:
			printf("There is no the function !\n");
			printf("==================================\n");
		}
	} while (states != 4);
	
	fclose(inp);
	system("pause");
	return 0;
}