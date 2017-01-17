#ifndef LL_H_
#define LL_H_

typedef struct no {

	char *palavra;
	int contador;
	struct no *prox;
} celula;

typedef celula* apontador;

void imprimeLista(apontador p);

void split(apontador fonte, apontador* frontRef, apontador* backRef);

apontador merge(apontador a, apontador b);

void mergeSort(apontador* inicioRef);

apontador insereOrdenado(apontador inicio, char *c);

apontador insereDesordenado(apontador inicio, char *c);


#endif //LL_H_
