#include <stdio.h>
#include <stdlib.h>

int pilhaVazia(pilha p){

	return p.topo == 0;
}

pilha* criaPilha(int max){

	pilha *p;
	p = malloc(sizeof(pilha));
	p -> v = malloc(sizeof(int)*max);
	p -> topo = 0;
	p -> max = max;

	return p;
}

void realocaPilha(pilha* p){

	int maxNovo = 1.2*((*p).max);
	int* w;
	w = malloc(sizeof(int)*maxNovo);
	int i;

	for(i = 0; i < (*p).max; i++)
		w[i] = (*p).v[i];

	free((*p).v);
	(*p).v = w;
}

void empilha(pilha* p, int x){

	if ((*p).topo == (*p).max){
		realocaPilha(p);
	}

	(*p).v[(*p).topo] = x;
	((*p).topo)++;
}

int desempilha(pilha* p){

	int x;
	if (pilhaVazia(*p)) return -1;
	else {
		x = (*p).v[--((*p).topo)];
	}

	return x;
}

void destroiPilha(pilha* p){

	free(p->v);
	free(p);
}
