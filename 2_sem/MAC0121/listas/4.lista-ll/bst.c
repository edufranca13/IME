#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct reg {

	int data;
	struct reg* left;
	struct reg* right;

} node;

node* insertNode(node* root, int x){

	if (root == NULL){
		node* new = malloc(sizeof(node));
		new->data = x;
		new->left = NULL;
		new->right = NULL;
		root = new;
	}
	else {
		if (x > root->data)
			root->right = insertNode(root->right, x);
		else
			root->left = insertNode(root->left, x);
	}

	return root;
}

bool searchData(node* root, int x){

	if (root == NULL){
		return false;
	}
	else if (root->data == x)
		return true;
	else if (x > root->data){
		return searchData(root->right, x);
	}
	else
		return searchData(root->left, x);
}

void printBST(node* root){

	if (root == NULL)
		return;
	else{
		printf("%d ", root->data);
		printBST(root->left);
		printBST(root->right);
	}
}

int main(int argc, char const *argv[])
{

	node* root = malloc(sizeof(node));
	root = NULL;

	root = insertNode(root, 20);
	root = insertNode(root, 12);
	root = insertNode(root, 30);
	root = insertNode(root, 10);
	root = insertNode(root, 5);
	root = insertNode(root, 40);
	root = insertNode(root, 25);

	printBST(root);
	printf("\n");

	bool one = searchData(root, 5);
	printf("data found? %d ", one);
	
	return 0;
}