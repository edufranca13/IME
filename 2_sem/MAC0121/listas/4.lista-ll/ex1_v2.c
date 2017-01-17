#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg* prox;
} celula;

typedef celula* apontador;

apontador insereOrdenado(apontador inicio, int data){

	apontador p, ant;
	apontador novo = malloc(sizeof(celula));
	novo->data = data;

	p = inicio;
	ant = NULL;

	while (p != NULL && data > p->data){
		ant = p;
		p = p->prox;
	}

	if (ant == NULL){
		novo->prox = inicio;
		inicio = novo;
	}
	else{
		novo->prox = p;
		ant->prox = novo;
	}

	return inicio;
}

void removeData(apontador inicio, int data){

	if (inicio == NULL)
		return;
	apontador q = inicio->prox;

	while (q != NULL && q->data != data){
		inicio = q;
		q = q->prox;
	}

	if (q != NULL){
		inicio->prox = q->prox;
		free(q);
	}
}

void imprimeLista(apontador inicio){

	while (inicio != NULL){
		printf("%d ", inicio->data);
		inicio = inicio->prox;
	}
	printf("\n");
}

void removeDuplicatas(apontador inicio){

	apontador p1, p2;
	p1 = inicio;

	while (p1 != NULL && p1->prox != NULL){
		p2 = p1;
		while (p2->prox != NULL){
			if (p1->data == p2->prox->data)
				removeData(p2, p2->data);
			else
				p2 = p2->prox;
		}
		p1 = p1->prox;
	}
}


int main(int argc, char const *argv[])
{

	apontador p1 = NULL;

	p1 = insereOrdenado(p1, 19);
	p1 = insereOrdenado(p1, 12);
	p1 = insereOrdenado(p1, 4);
	p1 = insereOrdenado(p1, 3);
	p1 = insereOrdenado(p1, 19);
	p1 = insereOrdenado(p1, 12);
	p1 = insereOrdenado(p1, 4);
	p1 = insereOrdenado(p1, 3);

	imprimeLista(p1);

	removeData(p1, 3);

	imprimeLista(p1);

	removeDuplicatas(p1);

	imprimeLista(p1);



	return 0;
}