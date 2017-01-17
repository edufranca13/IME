#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg *prox;

} celula;


void insereNoComeco(celula **lista, int data){

	celula *novo = malloc(sizeof(celula));
	novo->data = data;
	novo->prox = *lista;
	*lista = novo;
}

void imprimeLista(celula *lista){

	celula *p;
	for (p = lista->prox; p != NULL; p = p->prox)
		printf("%d ", p->data);
	printf("\n");
}

int procuraElemento(celula *lista, int data){

	int cont = 0;
	celula *p;
	for (p = lista->prox; p != NULL; p = p->prox){
		if (p->data == data)
			return cont;
		else
			cont++;
	}
	return -1;
}

void removeConteudo(celula *lista, int data){

	celula *p = lista;
	if (p == NULL)
		return;
	celula *q = p->prox;

	while (q != NULL && q->data != data){
		p = q;
		q = q->prox;
	}
	if (q != NULL){
		p->prox = q->prox;
		free(q);		
	}
}

void removeDuplicatas(celula *lista){

	celula *p;
	for (p = lista->prox; p != NULL; p = p->prox){
		removeConteudo(p->prox, p->data);
	}
}

int main(int argc, char const *argv[])
{
	
	celula *lista = malloc(sizeof(celula));
	lista->prox = NULL;

	insereNoComeco(&lista->prox, 5);
	insereNoComeco(&lista->prox, 18);
	insereNoComeco(&lista->prox, 20);
	insereNoComeco(&lista->prox, 1);
	insereNoComeco(&lista->prox, 5);
	insereNoComeco(&lista->prox, 1);
	insereNoComeco(&lista->prox, 10);
	insereNoComeco(&lista->prox, 18);

	imprimeLista(lista);

	removeDuplicatas(lista);

	imprimeLista(lista);



	return 0;
}