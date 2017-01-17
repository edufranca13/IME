#include <stdio.h>
#include <stdlib.h>


typedef struct {

	int *v;
	int topo;
	int max;

} pilha;

pilha *criaPilha(int max){

	pilha *p;
	p = malloc(sizeof(pilha));
	p->v = malloc(sizeof(int)*max);

	p->max = max;
	p->topo = 0;

	return p;
}

int pilhaVazia(pilha p){
	return p.topo == 0;
}

void realocaPilha(pilha *p){

	int novoMax = 2*p->max;

	int *w;

	w = malloc(sizeof(int)*novoMax);

	int i;
	for (i = 0; i < p->max; i++){
		w[i] = p->v[i];
	}

	free(p->v);
	p->v = w;
	p->max = novoMax;
}

void empilha(pilha *p, int x){

	if (p->topo == p-> max)
		realocaPilha(p);

	p->v[p->topo++] = x;
}

int desempilha(pilha *p){

	if (pilhaVazia(*p))
		printf("erro");;
	int x;
	x = p->v[--(p->topo)];

	return x;
}

void imprimePilha(pilha *p){

	int i;
	for (i = 0; i < p->topo; i++)
		printf("%d ", p->v[i]);
}

int main () {

	pilha *p;

	p = criaPilha(10);

	empilha(p, 5);
	empilha(p, 10);
	desempilha(p);

	imprimePilha(p);

	return 0;
}
