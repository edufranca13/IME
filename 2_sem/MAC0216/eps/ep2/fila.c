#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int inicio;
	int fim;
	int *v;
	int max;

} fila;

fila *criaFila(int max){

	fila *f;
	f = malloc(sizeof(fila));
	f->v = malloc(sizeof(int)*max);

	f->inicio = f->fim = 0;
	f->max = max;

	return f;
}

int filaVazia(fila f){
	return f.inicio == f.fim;
}

int filaCheia(fila f){
	return f.inicio + 1 == f.fim; 
}

void realocaFila(fila *f){

	int maxNovo = 2*(f->max);
	int *w;
	w  = malloc(sizeof(int)*maxNovo);

	int i;
	int j = 0;
	if (f->inicio < f->fim)
		for (i= f->inicio; i < f->fim; i++){
			w[j++] = f->v[i]; 
		}
	else if (f->inicio > f->fim){
		for (i = f->inicio; i < f->max; i++)
			w[j++] = f->v[i]; 			
		for (i = 0; i < f->fim; i++)
			w[j++] = f->v[i]; 
	}

	free(f->v);
	f->v = w;
	f->max = maxNovo;
}

void insere(fila *f, int x){

	if (filaCheia(*f)){
		realocaFila(f);
	}

	f->v[f->fim] = x;
	f->fim = (f->fim + 1) % f->max;
}

int remover(fila *f){

	if (filaVazia(*f))
		printf("erro\n");

	int x;
	x = f->v[f->inicio];
	f->inicio = (f->inicio + 1) % f->max;

	return x;
}

void imprimeFila(fila f){

	int i;
	if (f.inicio < f.fim)
		for (i = f.inicio; i < f.fim; i++){
			printf("%d\n", f.v[i]);
		}
	else if (f.inicio > f.fim){
		for (i = f.inicio; i < f.max; i++)
			printf("%d\n", f.v[i]);
		for (i = 0; i < f.fim; i++)
			printf("%d\n", f.v[i]);
	}
}

int main() {

	fila *f;
	f = criaFila(5);

	insere(f, 1);
	insere(f, 2);
	insere(f, 3);
	insere(f, 4);
	insere(f, 5);
	insere(f, 6);

	remover(f);
	remover(f);
	remover(f);
	remover(f);
	remover(f);

	insere(f, 1);

	imprimeFila(*f);



	return 0;
}