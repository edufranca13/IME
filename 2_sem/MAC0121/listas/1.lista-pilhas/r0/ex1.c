#include <stdio.h>
#include <stdlib.h>

typedef struct ref {

	int* v;
	int max;
	int topo;

}pilha;

pilha* criaPilha(int max){

	pilha* p = malloc(sizeof(pilha));
	p->v = malloc(sizeof(int)*max);

	p->max = max;
	p->topo = 0;

	return p;
}

void empilha(pilha* p, int x){

	p->v[topo] = x;
	p->topo++;
}

int main(){


}
