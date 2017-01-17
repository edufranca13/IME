#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	char *palavra;
	int contador;
	struct no *prox;
} celula;

typedef celula *apontador;

void imprimeLista(apontador p){

	if (p != NULL){
		printf("%s: %d \n", p->palavra, p->contador);
		imprimeLista(p->prox);
	}
}

apontador insereDesordenado(apontador inicio, char *c){


	apontador p, ant, novo;

	novo = malloc(sizeof(celula));
	novo->palavra = c;

	p = inicio;
	ant = NULL;

	while (p != NULL && strcmp(p->palavra, c) != 0){
		ant = p;
		p = p->prox;
	}

	if (p != NULL && strcmp(p->palavra, c) == 0){
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

	p = insereDesordenado(p, "coisa");
	p = insereDesordenado(p, "mais");
	p = insereDesordenado(p, "mais");
	p = insereDesordenado(p, "avemantes");
	p = insereDesordenado(p, "bvemdepois");
	p = insereDesordenado(p, "avemantes");
	p = insereDesordenado(p, "mais");
	p = insereDesordenado(p, "coisa");

	imprimeLista(p);
	
	return 0;
}