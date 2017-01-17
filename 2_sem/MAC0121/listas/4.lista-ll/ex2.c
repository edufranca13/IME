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

celula* insereNoFim(celula* inicio, int data){

	celula* p = inicio;
	celula* ant = NULL;
	while (p != NULL){
		ant = p;
		p = p->prox;
	}

	celula* novo = malloc(sizeof(celula));
	novo->data = data;

	if (ant == NULL){
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

void deletaCelula(celula** inicio, int data){

	if (*inicio == NULL)
		return;

	celula* p = *inicio;
	celula* ant = NULL;

	while (p != NULL && p->data != data){
		ant = p;
		p = p->prox;
	}

	if (ant == NULL){
		*inicio = p->prox;
		return;
	}

	if (p != NULL){
		ant->prox = p->prox;
	}
}

int verificaElemento(celula* p, int x){

	if (p == NULL)
		return 0;
	else if (p->data == x)
		return 1;
	else
		return verificaElemento(p->prox, x);
}




int main(int argc, char const *argv[])
{
	celula* inicio = NULL;

	inicio = insereOrdenado(inicio, 10);
	inicio = insereOrdenado(inicio, 5);
	inicio = insereOrdenado(inicio, 3);
	inicio = insereOrdenado(inicio, 4);

	imprimeLista(inicio);

	deletaCelula(&inicio, 10);

	imprimeLista(inicio);

	inicio = insereOrdenado(inicio, 18);
	inicio = insereOrdenado(inicio, 21);

	imprimeLista(inicio);

	printf("%d\n", verificaElemento(inicio, 192));


	inicio = insereNoFim(inicio, 15);

	imprimeLista(inicio);



	return 0;
}