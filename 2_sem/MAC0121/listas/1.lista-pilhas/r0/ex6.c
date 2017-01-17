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

char topoPilha(pilha p){
	if (pilhaVazia(p))
		return '3';
	else
		return p.v[p.topo-1];
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

void empilha(pilha* p, char x){
	
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
int precedencia(char x1, char x2){
	int p1, p2;

	if (x2 == '3')
		return 0;	

	switch (x1) {
		case '(':
			p1 = 0;
			break;
		case '+':
			p1 = 2;
			break;
		case '-':
			p1 = 2;
			break;
		case '*':
			p1 = 1;			
			break;
		case '/':
			p1 = 1;
			break;
		case ')':
			p1 = 0;
			break;
	}	
	
	switch (x2) {
		case '(':
			p1 = 0;
			break;
		case '+':
			p2 = 2;
			break;
		case '-':
			p2 = 2;
			break;
		case '*':
			p2 = 1;
			break;
		case '/':
			p2 = 1;
			break;
		case ')':
			p2 = 0;
			break;
	}	
	return p1 > p2;
}

int  main(int argc, char const *argv[]) {

	pilha* p = criaPilha(5);
	
	char c;	

	while((c = getchar()) != EOF){
		
		switch(c) {				
			case '(':
				empilha(p, c);
				break;
			case ')':
				while ((c = desempilha(p)) != '(')
					printf("%c", c);
				break;
			case '+':
				if (precedencia(c, topoPilha(*p)))
					printf("%c", desempilha(p));
				else
					empilha(p,c);
				break;
			case '-':
				if (precedencia(c, topoPilha(*p)))
					printf("%c", desempilha(p));
				else
					empilha(p,c);
				break;
			case '*':
				if (precedencia(c, topoPilha(*p)))
					printf("%c", desempilha(p));
				else
					empilha(p,c);
				break;
			case '/':
				if (precedencia(c, topoPilha(*p)))
					printf("%c", desempilha(p));
				else
					empilha(p,c);
				break;
			default:
				printf("%c", c);
				break;
			}	
		}

	while(!pilhaVazia(*p))
		printf("%c", desempilha(p));

	return 0;
}
