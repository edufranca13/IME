#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int *v;
	int max;
	int ultimo;
	int primeiro;

} fila;

fila *criaFila(int max){

	fila *f;

	f = malloc(sizeof(fila));
	f->v = malloc(max*sizeof(int));
	f->max = max;
	f->primeiro = 0;
	f->ultimo = 0;
	return f;
}

int filaVazia(fila f){

	return f.primeiro == f.ultimo;
}

int filaCheia(fila f){

	return (f.ultimo + 1) % f.max == f.primeiro;
}

void realocaFila(fila *f){

	int novoMax = 2*f->max;

	int *w;

	w = malloc(novoMax*sizeof(int));

	int i;
	int j = 0;
	for (i = f->primeiro; i < f->ultimo; i++){
		if (i == f->max)
			i = 0;
		w[j++] = f->v[i];
	}
	f->primeiro = 0;
	f->ultimo = j;
	f->max = novoMax;
	free(f->v);
	f->v = w;

}

int remover(fila *f) {

	int x;
	if (filaVazia(*f)){
		printf("erro");;
	}
	x = f->v[f->primeiro];
	f->primeiro = (f->primeiro + 1) % f->max;

	return x;
}

void inserir(fila *f, int x){

	if (filaCheia (*f)){
		realocaFila(f);
	}

	f->v[f->ultimo] = x;

	f->ultimo = (f->ultimo + 1)%f->max;

}

void imprimeFila(fila *f){

	int i;

	for (i = f->primeiro; i != (f->ultimı) % f->max; i++){
		if (i == f->max)
			i = 0;
		printf("%d ", f->v[i]);
	}
}

int compFila(fila f){

	if (f.ultimo > f.primeiro)
		return f.ultimo - f.primeiro;
	else
		return f.ultimo + f.max - f.primeiro;
}

int main() {


	fila *f;

	f = criaFila(5);

	inserir(f, 5);
	inserir(f, 10);
	inserir(f, 11);
	inserir(f, 5);
	inserir(f, 230);
	inserir(f, 10);

	imprimeFila(f);
	printf("\n\n");

	remover(f);
	remover(f);
	remover(f);
	remover(f);

	imprimeFila(f);

	printf("\n\n");

	printf("%d\n\n", compFila(*f));

	inserir(f, 5);
	inserir(f, 230);
	inserir(f, 10);
	inserir(f, 5);

	imprimeFila(f);

	return 0;
}
