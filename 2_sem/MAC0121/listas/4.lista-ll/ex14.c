#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	float coef;
	int expo;
	struct reg *prox;

} celula;

typedef celula* apontador;

apontador insereOrdenado(apontador inicio, float coef, int expo){

	apontador p, ant;
	apontador novo = malloc(sizeof(celula));
	novo->expo = expo;
	novo->coef = coef;

	p = inicio;
	ant = NULL;

	while (p != NULL && expo > p->expo){
		ant = p;
		p = p->prox;
	}

	if (p != NULL && expo == p->expo){
		p->coef += coef;
	}

	else if (ant == NULL){
		novo->prox = inicio;
		inicio = novo;
	}
	else {
		novo->prox = p;
		ant->prox = novo;
	}

	return inicio;
}

apontador somaPolinomios(apontador p1, apontador p2){

	apontador soma = malloc(sizeof(celula));
	soma = NULL;

	while (p1 != NULL && p2 != NULL){
		if (p1->expo == p2->expo){
			soma = insereOrdenado(soma, p1->coef + p2->coef, p1->expo);
			p1 = p1->prox;
			p2 = p2->prox;
		}
		else if (p1->expo < p2->expo){
			soma = insereOrdenado(soma, p1->coef, p1->expo);
			p1 = p1->prox;
		}
		else{
			soma = insereOrdenado(soma, p2->coef, p2->expo);
			p2 = p2->prox;
		}
	}

	while (p1 != NULL){
		soma = insereOrdenado(soma, p1->coef, p1->expo);
		p1 = p1->prox;
	}
	while (p2 != NULL){
		soma = insereOrdenado(soma, p2->coef, p2->expo);
		p2 = p2->prox;
	}
	
	return soma;
}

apontador derivaPolinomio(apontador p1){

	apontador d1 = malloc(sizeof(celula));
	d1 = NULL;

	while (p1 != NULL){
		d1 = insereOrdenado(d1, p1->coef*p1->expo, p1->expo - 1);
		p1 = p1->prox;
	}

	return d1;
}


void imprimeLista(apontador inicio){

	if (inicio == NULL)
		return;
	else {
		printf("%.2f^%d ", inicio->coef, inicio->expo);
		imprimeLista(inicio->prox);
	}
}

int main(int argc, char const *argv[])
{
	
	apontador p1 = NULL;
	p1 = insereOrdenado(p1, 2.4, 2);
	p1 = insereOrdenado(p1, 1.7, 3);
	p1 = insereOrdenado(p1, 3, 4);
	p1 = insereOrdenado(p1, 2, 8);

	imprimeLista(p1);
	printf("\n");

	apontador p2 = NULL;
	p2 = insereOrdenado(p2, 1.6, 2);
	p2 = insereOrdenado(p2, 1.3, 3);
	p2 = insereOrdenado(p2, 1, 4);
	p2 = insereOrdenado(p2, 2, 8);

	imprimeLista(p2);
	printf("\n");

	apontador soma = somaPolinomios(p1, p2);

	imprimeLista(soma);
	printf("\n");

	apontador d1 = derivaPolinomio(soma);

	imprimeLista(d1);

	return 0;
}