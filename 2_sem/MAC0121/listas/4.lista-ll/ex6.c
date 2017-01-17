#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg* prox;

} celula;


celula* insereOrdenado(celula* inicio, int data){

	celula* p;
	celula* ant;

	celula* novo = malloc(sizeof(celula));
	novo->data = data;

	p = inicio;
	ant = NULL;

	while (p != NULL && p->data < data){
		ant = p;
		p = p->prox;
	}
	//primeira celula a ser inserida
	if (ant == NULL) {
		novo->prox = inicio;
		inicio = novo;
	}
	else {
		ant->prox = novo;
		novo->prox = p;
	}

	return inicio;
}

void imprimeLista(celula* p){

	while (p != NULL){
		printf("%d ", p->data);
		p = p->prox;
	}
	printf("\n");
}

celula* intercala(celula* p1, celula* p2){

	celula* nova = malloc(sizeof(celula));
	nova = NULL;

	while (p1 != NULL && p2 != NULL){
		if (p1->data < p2->data){
			nova = insereOrdenado(nova, p1->data);
			p1 = p1->prox;
		}
		else {
			nova = insereOrdenado(nova, p2->data);
			p2 = p2->prox;
		}
	}

	while (p1 != NULL){
		nova = insereOrdenado(nova, p1->data);
		p1 = p1->prox;		
	}

	while (p2 != NULL){
		nova = insereOrdenado(nova, p2->data);
		p2 = p2->prox;
	}

	return nova;
}

int main(int argc, char const *argv[])
{
	celula* p1 = malloc(sizeof(celula));
	p1 = NULL;

	p1 = insereOrdenado(p1, 2);
	p1 = insereOrdenado(p1, 8);
	p1 = insereOrdenado(p1, 5);

	imprimeLista(p1);

	celula* p2 = malloc(sizeof(celula));
	p2 = NULL;

	p2 = insereOrdenado(p2, 9);
	p2 = insereOrdenado(p2, 6);

	imprimeLista(p2);

	celula* nova = intercala(p1, p2);

	imprimeLista(nova);




	return 0;
}