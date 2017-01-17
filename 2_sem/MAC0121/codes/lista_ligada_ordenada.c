#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {

	char *palavra;
	int contador;
	struct no *prox;
} celula;

typedef celula* apontador;


void split(apontador fonte, apontador* frontRef, apontador* backRef){

	apontador fast;
	apontador slow;

	if (fonte == NULL || fonte->prox == NULL){
		*frontRef = fonte;
		*backRef = NULL;
	}
	else {
		slow = fonte;
		fast = fonte->prox;

		while (fast != NULL){
			fast = fast->prox;
			if (fast != NULL){
				slow = slow->prox;
				fast = fast->prox;
			}
		}

	*frontRef = fonte;
	*backRef = slow->prox;
	slow->prox = NULL;
	}
}

apontador merge(apontador a, apontador b){

	apontador p = NULL;

	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	if (a->contador <= b->contador){
		p = a;
		p->prox = merge(a->prox, b);
	}
	else {
		p = b;
		p->prox = merge(a, b->prox);
	}

	return p;
}

void mergeSort(apontador* inicioRef){

	apontador inicio = *inicioRef;
	apontador a;
	apontador b;

	if (inicio == NULL || inicio->prox == NULL){
		return;
	}

	split(inicio, &a, &b);

	mergeSort(&a);
	mergeSort(&b);

	*inicioRef = merge(a, b);
}

void imprimeLista(apontador p){

	if (p != NULL){
		printf("%s: %d \n", p->palavra, p->contador);
		imprimeLista(p->prox);
	}
}

apontador insereOrdenado(apontador inicio, char *c){

	apontador p, ant, novo;

	char* c2;
	c2 = malloc(1024);
	strcpy(c2, c);

	novo = malloc(sizeof(celula));
	novo->palavra = c2;

	p = inicio;
	ant = NULL;

	while (p != NULL && strcmp(p->palavra, c2) < 0){
		ant = p;
		p = p->prox;
	}

	if (p != NULL && strcmp(p->palavra, c2) == 0){
		p->contador++;
		return inicio;
	}

	if (ant == NULL){
		novo->prox = inicio;
		inicio = novo;
		novo->contador = 1;
	}

	else {
		novo->prox = ant->prox;
		ant->prox = novo;
		novo->contador = 1;
	}

	return inicio;
}

int main(int argc, char const *argv[])
{

	apontador p = NULL;

	p = insereOrdenado(p, "coisa");
	p = insereOrdenado(p, "mais");
	p = insereOrdenado(p, "mais");
	p = insereOrdenado(p, "avemantes");
	p = insereOrdenado(p, "bvemdepois");
	p = insereOrdenado(p, "avemantes");

	mergeSort(&p);

	imprimeLista(p);
	
	return 0;
}