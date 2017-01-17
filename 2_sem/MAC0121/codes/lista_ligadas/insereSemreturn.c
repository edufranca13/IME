#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg *prox;

} celula;

celula *traverse(celula **lista) {

	celula *temp = *lista;

	while (temp->prox != NULL)
		temp = temp->prox;

	return temp;
}

celula *traverseP(celula **lista, int posicao){

	celula *temp = *lista;

	int i;

	for (i = 0; i < posicao; i++){
		if (temp->prox == NULL){
			printf("posição inválida\n");
			exit(1);
		}
		else
			temp = temp->prox;
	}
	return temp;
}

void insereNoComeco(celula **lista, int data){

	celula *novo = malloc(sizeof(celula));
	novo->data = data;
	novo->prox = *lista;

	*lista = novo;
}

void insereNoFinal(celula **lista, int data){

	celula *novo = malloc(sizeof(celula));
	novo->data = data;
	novo->prox = NULL;

	celula *temp = traverse(lista);
	temp->prox = novo;
}

void insereNaPosicao(celula **lista, int data, int posicao){

	if (posicao < 0){
		printf("posição inválida (menor que zero)\n");
		exit(1);
	}

	celula *temp = traverseP(lista, posicao);

	celula *novo = malloc(sizeof(celula));
	novo->data = data;
	novo->prox = temp->prox;
	temp->prox = novo;
}

void imprimeListaR(celula *lista){

	if (lista == NULL)
		return;
	else{
		printf("%d ", lista->data);
		imprimeListaR(lista->prox);
	}
}

void imprimeLista(celula *lista){

	while (lista != NULL){
		printf("%d ", lista->data);
		lista = lista->prox;
	}

	printf("\n");

}

int main(int argc, char const *argv[])
{

	celula *lista;
	lista = NULL;

	insereNoComeco(&lista, 20);
	insereNoComeco(&lista, 10);
	insereNoComeco(&lista, 5);
	insereNoComeco(&lista, 4);
	insereNoFinal(&lista, 15);
	imprimeLista(lista);

	insereNaPosicao(&lista, 128, 3);

	imprimeLista(lista);

	insereNaPosicao(&lista, 112, 0);

	imprimeLista(lista);

	
	return 0;
}