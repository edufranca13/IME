#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg *prox;

} celula;

void insereNoComeco(celula **lista, int data) {

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

int altura(celula *a){

	int alt = 0;
	while (a != NULL){
		alt++;
		a = a->prox;
	}

	return alt;
}

celula *traverseP(celula *cel, int pos){

	int i;
	for (i = 0; i < pos; i++)
		cel = cel->prox;

	return cel;
}

int main(int argc, char const *argv[])
{
	
	celula *lista = NULL;
	insereNoComeco(&lista, 10);
	insereNoComeco(&lista, 20);
	insereNoComeco(&lista, 1);
	insereNoComeco(&lista, 21);
	insereNoComeco(&lista, 123);
	insereNoComeco(&lista, 40);

	celula *temp = traverseP(lista, 5);

	printf("%d\n", temp->data);

	imprimeLista(lista);

	int d = altura(temp);

	printf("%d\n", d);

	return 0;
}