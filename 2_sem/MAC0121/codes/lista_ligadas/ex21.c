#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg *prox;

} celula;

void *insere(celula *lista, int data){

	celula *novo = malloc(sizeof(celula));
	novo->data = data;

	if (lista == NULL){
		novo->prox = NULL;		
	}
	else {
		novo->prox = lista;
	}
	lista = novo;

	return lista;
}


int contaListaR(celula *lista) {

	if (lista == NULL)
		return 0;
	else
		return 1 + contaListaR(lista->prox);
}

int contaLista(celula *lista){

	int conta = 0;
	while (lista != NULL){
		conta++;
		lista = lista->prox;
	}
	return conta;
}

void imprimeListaR(celula *lista){

	if (lista == NULL)
		return;
	else{
		printf("%d ", lista->data);
		imprimeListaR(lista->prox);
	}
}

int main(int argc, char const *argv[])
{

	celula *lista;
	lista = NULL;
	lista = insere(lista, 10);
	lista = insere(lista, 20);
	lista = insere(lista, 15);
	lista = insere(lista, 30);
	lista = insere(lista, 20);

	int n = contaListaR(lista);
	int n2 = contaLista(lista);

	printf("%d %d\n", n, n2);

	imprimeListaR(lista);

	
	return 0;
}