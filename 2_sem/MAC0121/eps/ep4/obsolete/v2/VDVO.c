#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "VDVO.h"

void imprimeV(vetor *p){

	int i;
	for (i = 0; i < p->ultimo; i++)
		printf("%s : %d\n", p->data[i].palavra, p->data[i].contador);
}

vetor *criaV(int n){

	vetor *p = malloc(sizeof(vetor));
	p->data = malloc(sizeof(data)*n);
	p->max = n;
	p->ultimo = 0;

	return p;
}

int buscaBinaria(vetor *p, char *c, int inicio, int fim){

	int meio;
	
	if (inicio > fim)
		return inicio;
	
	meio = (inicio + fim)/2;	

	if (strcmp(p->data[meio].palavra, c) == 0)
		return meio;
	else if (strcmp(p->data[meio].palavra, c) > 0)
		return buscaBinaria(p, c, inicio, meio - 1);
	else
		return buscaBinaria(p, c, meio + 1, fim);
	
}

void rearranjaV(vetor *p, int indice){

	vetor *w;
	int i;

	if (p->ultimo == p->max - 1)
		w = criaV(p->max*2);
	else
		w = criaV(p->max);

	for (i = 0; i < indice; i++)
		w->data[i] = p->data[i];

	for (i = indice + 1; i <= p->ultimo; i++)
		w->data[i] = p->data[i-1];

	free(p->data);
	p->data = w->data;
	p->max = w->max;

}