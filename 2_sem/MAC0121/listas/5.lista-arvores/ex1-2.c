#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct reg {

	int data;
	struct reg* left;
	struct reg* right;

} node;

node* getNewNode(int x){

	node* newNode = malloc(sizeof(node));
	newNode->data = x;
	newNode->left = newNode->right = NULL;

	return newNode;
}

node* insertBST(node* root, int x){

	if (root == NULL){
		root = getNewNode(x);
		return root;
	}
	else if (x > root->data){
		root->right = insertBST(root->right, x);
	}
	else
		root->left = insertBST(root->left, x);

	return root;
}

void printfBST(node* root){

	if (root == NULL)
		return;
	else {
		printf("%d ", root->data);
		printfBST(root->left);
		printfBST(root->right);
	}
}

int countNodes(node* root){

	if (root == NULL)
		return 0;
	else
		return 1 + countNodes(root->left) + countNodes(root->right);
}

bool ehAncestral(node* x, node* y){

	if (x == NULL)
		return false;

	else if (x == y)
		return true;
	else
		return (ehAncestral(x->left, y) || ehAncestral(x->right, y));

}

node* searchData(node* root, int x){

	if (root == NULL)
		exit(0);
	else if (x == root->data)
		return root;
	else if (x < root->data)
		return searchData(root->left, x);
	else
		return searchData(root->right, x);
}


int main(int argc, char const *argv[])
{
	
	node* root = NULL;

	root = insertBST(root, 20);
	root = insertBST(root, 12);
	root = insertBST(root, 30);
	root = insertBST(root, 8);
	root = insertBST(root, 25);

	printfBST(root);
	printf("\n");

	printf("numero de nos: %d\n", countNodes(root));

	node* x = searchData(root, 12);
	node* y = searchData(root, 8);

	printf("x eh ancestral de y? %d\n", ehAncestral(x, y));



	return 0;
}