#include <stdio.h>
#include <stdlib.h>


typedef struct reg {

	int data;
	struct reg* prox;
} celula;

void insere (celula **lista, int data){

	celula *novo = (celula *) malloc(sizeof(celula));

	novo->data = data;
	novo->prox = *lista;

	*lista = novo;
}

void imprimeLista(celula *lista){

	while (lista != NULL){
		printf("%d ", lista->data);
		lista = lista->prox;
	}
	printf("\n");
}

int listaEmOrdem(celula *lista){

	while (lista != NULL && lista->prox != NULL){
		if (lista->data > lista->prox->data)
			return 0;
		lista = lista->prox;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
		
	celula *lista = NULL;

	insere(&lista, 5);
	insere(&lista, 2);
	insere(&lista, 10);
	insere(&lista, 1);

	imprimeLista(lista);

	printf("%d\n", listaEmOrdem(lista));

	return 0;
}
