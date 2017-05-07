#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "LDLO.h"

void armazenaLista(apontador inicio, data arr[], int *index_ptr){
    
    data novo;

    if (inicio == NULL)
        return;

    novo.contador = inicio->data.contador;
    novo.palavra = inicio->data.palavra;

    arr[*index_ptr] = novo;
    (*index_ptr)++;

    armazenaLista(inicio->prox, arr, index_ptr);
}

void arrLL(data *arr, apontador inicio, int *index_ptr){
    
    if (inicio == NULL)
      return;

    inicio->data.contador = arr[*index_ptr].contador;
    inicio->data.palavra = arr[*index_ptr].palavra;
    (*index_ptr)++;

    arrLL(arr, inicio->prox, index_ptr);
}

int tamanhoLista(apontador inicio){

	if (inicio == NULL)
		return 0;
	else 
		return 1 + tamanhoLista(inicio->prox);
}

void sortLL(apontador inicio, char const *c) {

	int n;
	data *arr;
	int i;

    if(inicio == NULL)
       return;

    n = tamanhoLista(inicio);

    arr = malloc(sizeof(data)*n);

    i = 0;
    armazenaLista(inicio, arr, &i);

    if (strcmp(c, "O") == 0)
		qsort(arr, n, sizeof(arr[0]), compareO);
	else if (strcmp(c, "A") == 0)
		qsort(arr, n, sizeof(arr[0]), compareA);

    i = 0;
    arrLL(arr, inicio, &i);

    free(arr);
}

void imprimeL(apontador p){

	if (p != NULL){
		printf("%s: %d \n", p->data.palavra, p->data.contador);
		imprimeL(p->prox);
	}
}