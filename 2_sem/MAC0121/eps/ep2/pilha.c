#include <stdlib.h>
#include <stdio.h>
#include "auxResta.h"
#include "pilha.h"


int pilhaVazia(pilha p){

	return p.topo == 0;
}

pilha* criaPilha(int max){

	pilha *p;

	p = malloc(sizeof(pilha));

	p -> v = malloc(sizeof(pos)*max);

	p -> max = max;

	p -> topo = 0;

	return p;
}

void realocaPilha(pilha *p){

	pos *w;
	int i, novoMax;

	novoMax = 1.2*(p -> max);

	w = malloc(sizeof(pos)*novoMax);

	i = 0;

	for (i = 0; i < p -> max; i++)
		w[i] = (p -> v)[i];

	free(p -> v);
	p->v = w;
	p->max = novoMax;
}

void empilha(pilha *p, pos x){

	if (p-> topo == p -> max){
		realocaPilha(p);
	}

	p->v[p -> topo] = x;
	(p->topo)++;
}

pos desempilha(pilha *p){

	pos erro, x;

	if (pilhaVazia(*p)) {
		printf("Erro");
		return erro;
	}

	x = p -> v[--(p -> topo)];

	return x;
}

void destroiPilha(pilha *p){

	free(p -> v);
	free(p);
}

void imprimePilha(pilha *p){


	int i;
	for (i = 0; i < p-> topo; i++) {
		printf("%d:%d-", i, (p->v[i]).lin, (p->v[i]).col);
		switch((p->v[i]).mov){
			case 1:
				printf("%d:%d\n", (p->v[i]).lin, (p->v[i]).col + 2);
				break;
			case 2:
				printf("%d:%d\n", (p->v[i]).lin + 2, (p->v[i]).col);
				break;
			case 3:
				printf("%d:%d\n", (p->v[i]).lin, (p->v[i]).col - 2);
				break;
			case 4:
				printf("%d:%d\n", (p->v[i]).lin - 2, (p->v[i]).col);
				break;
		}
	}
}