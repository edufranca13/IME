#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
	
	char *v;
	int topo;
	int max;

} pilha;

pilha* criaPilha(int  max){

	pilha* p = malloc(sizeof(pilha));
	p->v = malloc(sizeof(char)*max);
	p->topo = 0;
	p->max = max;

	return p;
}
int pilhaVazia(pilha p){

	if (p.topo == 0)
		return 1;
	else
		return 0;
}

int pilhaCheia(pilha p){
	
	if(p.topo == p.max - 1)
		return 1;
	else
		return 0;
}

void realocaPilha(pilha *p){
	
	char* w = malloc(sizeof(int)*p->max*2);	
	int i;
	for (i = 0; i <= p->topo; i++)
		w[i] = p->v[i];
	free(p->v);
	p->v = w;
	p->max = p->max*2;	
}

void insere(pilha* p, char x){
	
	if(pilhaCheia(*p)){
		realocaPilha(p);
	}
	p->v[p->topo++]=x;
}

void imprimePilha(pilha p){

	int i;
	for (i = 0; i <= p.topo; i++)
		printf("%c ", p.v[i]);
}

char desempilha(pilha* p){

	if (pilhaVazia(*p))
		exit(1);

	char x;
	x = p->v[--(p->topo)];

	return x;
}

int  main(int argc, char const *argv[]) {

	pilha* p = criaPilha(5);
	char c, x;
	while((c = getchar()) != '.')
		if (c != ' '){
			insere(p, c);
		}
		else {
			while(!pilhaVazia(*p)){
				x  = desempilha(p);
				printf("%c", x);
			}
			printf(" ");
		}

	while(!pilhaVazia(*p)){
		x  = desempilha(p);
		printf("%c", x);
	}

	printf(".\n");
	
	return 0;
}
