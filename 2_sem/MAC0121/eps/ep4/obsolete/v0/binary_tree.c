#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {

	int contador;
	char *palavra;
	struct no *esq;
	struct no *dir;
} celula;

typedef celula *apontador;

void inorder(apontador raiz){

	if (raiz != NULL) {
		inorder(raiz->esq);
		printf("%s : %d \n", raiz->palavra, raiz->contador);
		inorder(raiz->dir);
	}	
}

apontador novaCelula(char *c){

	apontador novo = malloc(sizeof(celula));
	novo->palavra = c;
	novo->contador = 1;
	novo->dir = novo->esq = NULL;

	return novo;
}

apontador insereAB(apontador raiz, char *c){

	char *c2 = malloc(1024);
	strcpy(c2, c);

	if (raiz == NULL){
		raiz = novaCelula(c2);
		return raiz;
	}

	else if (strcmp(raiz->palavra, c2) < 0)
		raiz->esq = insereAB(raiz->esq, c2);
	else if (strcmp(raiz->palavra, c2) > 0)
		raiz->dir = insereAB(raiz->dir, c2);
	else
		raiz->contador++;

	return raiz;
}

apotandor sortABB(apontador raiz){

	if (raiz != NULL){
		apontador arv2 = insereAB()
	}


}

int main(int argc, char const *argv[]) {

	apontador p = NULL;

	p = insereAB(p, "chocolate");
	p = insereAB(p, "quente");
	p = insereAB(p, "chocolate");
	p = insereAB(p, "quente");
	p = insereAB(p, "a");
	p = insereAB(p, "b");
	p = insereAB(p, "0");


	inorder(p);
	return 0;
}