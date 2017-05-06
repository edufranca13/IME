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

node* createTreeFromTraversal(int pre[], int[]in){

	/* é o seguinte: 
	1) o primeiro valor do preorder é a raiz
	2) eu caminho no preorder e pego o segundo valor
	3) comparo a posicao, dentro do vetor inorder, do segundo com o valor
	obtido da propria arvore 
	4) se estiver a esquerda eu me movo para esquerda na arvore 
	e faco a mesma comparacao
	5) se, no entanto, for null, eu insiro nessa posicao (a esquerda)
	6) se estiver a direita eu me movo para direita na arvore 
	e faco a mesma comparacao
	7) se, no entanto for null, eu insiro nessa posicao (a direita)
	8) faco isso ate acabar com o vetor preorder */


}

int main(int argc, char const *argv[])
{
	int preorder[5] = {1,2,4,5,3};
	int inorder[5] = {4,2,5,1,3};


	return 0;
}


