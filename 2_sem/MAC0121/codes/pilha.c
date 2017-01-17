#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int* v;
	int max;
	int topo;

} pilha;

pilha *criaPilha(int max) {

	pilha *p;
	p = malloc(sizeof(pilha));
	(*p).v = malloc(sizeof(int)*max);
	(*p).max = max;
	(*p).topo = 0;

	return p;
}

int pilhaVazia(pilha p){

	return p.topo == 0;
}

void realocaPilha(pilha *p){

	int maxNovo = ((*p).max)*1.2;

	int *w;
	w = malloc(sizeof(int)*maxNovo);
	int i;
	for(i = 0; i < (*p).max; i++)
		w[i] = (*p).v[i];

	free((*p).v);
	(*p).v = w;
	(*p).max = maxNovo; 
}

void empilha(pilha *p, int x){

	if ((*p).topo == (*p).max)
		realocaPilha(p);
	(*p).v[(*p).topo] = x;
	((*p).topo)++;
}

int desempilha(pilha *p){

	int x;
	if (pilhaVazia(*p))
		return -1;
	else {
		x = (*p).v[--((*p).topo)];
	}

	return x;
}

int main() {

	pilha *p = criaPilha(10);

	empilha(p, 1);
	empilha(p, 7);
	empilha(p, 6);
	empilha(p, 5);
	empilha(p, 4);

	int i;
	int x;
	for (i = 0; i < 5; i++) {
		x = desempilha(p);
		printf("%d\n", x);
	}


	return 0;
}