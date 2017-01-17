#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "LDLO.h"
#include "tabelaSimbolo_LD.h"

apontador insereDesordenadoL(apontador inicio, char *c){

	apontador p, ant, novo;

	char* c2 = malloc(1024);
	strcpy(c2, c);

	novo = malloc(sizeof(celula));
	novo->data.palavra = c2;

	p = inicio;
	ant = NULL;

	while (p != NULL && strcmp(p->data.palavra, c2) != 0){
		ant = p;
		p = p->prox;
	}

	if (p != NULL && strcmp(p->data.palavra, c2) == 0){
		free(novo);
		p->data.contador++;
		return inicio;
	}

	novo->prox = inicio;
	inicio = novo;
	novo->data.contador = 1;

	return inicio;
}