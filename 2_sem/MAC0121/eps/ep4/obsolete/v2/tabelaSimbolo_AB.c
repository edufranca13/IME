#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "tabelaSimbolo_AB.h"

void imprimeEmOrdem(apontadorA raiz){

	if (raiz != NULL) {
		imprimeEmOrdem(raiz->esq);
		printf("%s : %d \n", raiz->data.palavra, raiz->data.contador);
		imprimeEmOrdem(raiz->dir);
	}	
}

apontadorA novaCelula(char *c){

	apontadorA novo = malloc(sizeof(ramo));
	novo->data.palavra = c;
	novo->data.contador = 1;
	novo->dir = novo->esq = NULL;

	return novo;
}

apontadorA insereAB(apontadorA raiz, char *c){

	char *c2 = malloc(1024);
	strcpy(c2, c);

	if (raiz == NULL){
		raiz = novaCelula(c2);
		return raiz;
	}

	else if (strcmp(raiz->data.palavra, c2) > 0)
		raiz->esq = insereAB(raiz->esq, c2);
	else if (strcmp(raiz->data.palavra, c2) < 0)
		raiz->dir = insereAB(raiz->dir, c2);
	else
		raiz->data.contador++;

	return raiz;
}

void armazenaArvore(apontadorA raiz, data arr[], int *index_ptr){

    data novo;

    if (raiz == NULL)
        return;

    armazenaArvore(raiz->esq, arr, index_ptr);

    novo.contador = raiz->data.contador;
    novo.palavra = raiz->data.palavra;

    arr[*index_ptr] = novo;
    (*index_ptr)++;

    armazenaArvore(raiz->dir, arr, index_ptr);
}

void arrAB (data *arr, apontadorA raiz, int *index_ptr){
    if (raiz == NULL)
      return;

    arrAB(arr, raiz->esq, index_ptr);

    raiz->data.contador = arr[*index_ptr].contador;
    raiz->data.palavra = arr[*index_ptr].palavra;
    (*index_ptr)++;

    arrAB(arr, raiz->dir, index_ptr);
}

int contaNos(apontadorA raiz) {
    if (raiz == NULL)
		return 0;
    return contaNos(raiz->esq) +
           contaNos(raiz->dir) + 1;
}

void sortAB(apontadorA raiz) {

    int n, i;
    data *arr;

    if(raiz == NULL)
       return;

    n = contaNos(raiz);

    arr = malloc(sizeof(data)*n);
    i = 0;
    armazenaArvore(raiz, arr, &i);

    qsort(arr, n, sizeof(arr[0]), compareO);

    i = 0;
    arrAB(arr, raiz, &i);

    free(arr);
}