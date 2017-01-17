#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	float coef;
	int expo;
	struct reg* prox;
} celula;

void insereNoComeco(celula **lista, float coef, int expo){

	celula *novo = malloc(sizeof(celula));
	novo->expo = expo;
	novo->coef = coef;
	novo->prox = (*lista)->prox;
	(*lista)->prox = novo;
}

void insereOrdenado(celula **lista, float coef, int expo){

	if ((*lista)->prox == NULL){
		insereNoComeco(lista, coef, expo);
		return;
	}

	celula* temp = (*lista)->prox;
	celula* temp2 = temp->prox;

	while(temp2 != NULL && temp->expo > expo){
		temp = temp2;
		temp2 = temp2->prox;
	}

	if (temp->expo == expo)
		temp->coef += coef;
	else if (temp->expo > expo) {
		celula *novo = malloc(sizeof(celula));
		novo->coef = coef;
		novo->expo = expo;
		temp->prox = novo;
		novo->prox = temp2;
	}
	else {
		insereNoComeco(lista, coef, expo);
	}
}

void imprimeLista(celula *lista){

	celula* p;
	for (p = lista->prox; p != NULL; p = p->prox)
		printf("%f^%d ", p->coef, p->expo);
	printf("\n");
}

celula* somaPolinomios(celula* p1, celula* p2){

	celula* soma = malloc(sizeof(celula));
	soma->prox = NULL;

	while (p1->prox != NULL && p2->prox != NULL){
		if (p1->prox->expo == p2->prox->expo){
			insereOrdenado(&soma, p1->prox->coef + p2->prox->coef, p1->prox->expo);
			p1 = p1->prox;
			p2 = p2->prox;
		}
		else if (p1->prox->expo > p2->prox->expo){
			insereOrdenado(&soma, p2->prox->coef, p2->prox->expo);
			p2 = p2->prox;
		}
		else {
			insereOrdenado(&soma, p1->prox->coef, p2->prox->expo);
			p1 = p1->prox;
		}
	}
	while (p1->prox != NULL){
		insereOrdenado(&soma, p1->prox->coef, p1->prox->expo);
		p1 = p1->prox;
	}
	while (p2->prox != NULL){
		insereOrdenado(&soma, p2->prox->coef, p2->prox->expo);
		p2 = p2->prox;
	}

	return soma;
}


int main(int argc, char const *argv[])
{

	celula *p1 = malloc(sizeof(celula));
	p1->prox = NULL;

	insereOrdenado(&p1, 1, 3);
	insereOrdenado(&p1, 3, 2);
	insereOrdenado(&p1, 2, 2);
	insereOrdenado(&p1, 8.5, 2);
	insereOrdenado(&p1, 2, 4);

	imprimeLista(p1);

	celula *p2 = malloc(sizeof(celula));
	p2->prox = NULL;

	insereOrdenado(&p2, 2, 3);
	insereOrdenado(&p2, 3, 2);
	insereOrdenado(&p2, 3, 6);
	insereOrdenado(&p2, 8.5, 2);
	insereOrdenado(&p2, 2, 4);

	imprimeLista(p2);
	
	celula* soma = somaPolinomios(p1, p2);

	imprimeLista(soma);

	return 0;
}