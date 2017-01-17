#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *v;
	int max;
	int topo;
} pilha;

int pilhaVazia(pilha p);

pilha* criaPilha(int max);

void realocaPilha(pilha* p);

void empilha(pilha* p, int x);

int desempilha(pilha* p);

void destroiPilha(pilha* p);
