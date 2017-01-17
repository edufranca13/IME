#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int *v;
	int max;
	int fim;
	int inicio;

} fila;

fila *criaFila(int max){

	fila *f;

	f = malloc(sizeof(fila));
	f->v = malloc(max*sizeof(int));
	f->max = max;
	f->inicio = f->fim = 0;
	return f;
}

int filaVazia(fila f){

	return f.inicio == f.fim;
}

int filaCheia(fila f){

	return (f.fim + 1) % f.max == f.inicio;
}

void realocaFila(fila *f){

	int novoMax = 2*f->max;

	int *w;

	w = malloc(novoMax*sizeof(int));

	int i;
	int j = 0;

	if (f->fim < f->inicio){
		for (i = f->inicio; i <= f->max; i++)
			w[j++] = f->v[i];
		for (i = 0; i < f->fim; i++)
			w[j++] = f->v[i];
	}
	else {
		for (i = f->inicio; i < f->fim; i++)
			w[j++] = f->v[i];
	}

	f->inicio = 0;
	f->fim = j;
	f->max = novoMax;
	free(f->v);
	f->v = w;
}

int remover(fila *f) {

	int x;
	if (filaVazia(*f)){
		printf("erro");;
		exit(1);
	}
	x = f->v[f->inicio];
	f->inicio = (f->inicio + 1) % f->max;

	return x;
}

void inserir(fila *f, int x){

	if (filaCheia (*f)){
		realocaFila(f);
	}

	f->v[f->fim++] = x;

	if (f->fim == f->max + 1){
		f->fim = 0;
	}

}

void imprimeFila(fila *f){

	int i;
	if (f->fim < f->inicio){
		for (i = f->inicio; i <= f->max; i++)
			printf("%d ", f->v[i]);
		for (i = 0; i < f->fim; i++)
			printf("%d ", f->v[i]);
	}
	else
		for (i = f->inicio; i < f->fim; i++)
			printf("%d ", f->v[i]);
	printf("\n");
}

int compFila(fila f){

	if (f.fim > f.inicio)
		return f.fim - f.inicio;
	else
		return f.fim + f.max - f.inicio;
}

int main() {


	fila *f;

	f = criaFila(5);

	inserir(f, 1);
	imprimeFila(f);
	inserir(f, 2);
	imprimeFila(f);
	inserir(f, 3);
	imprimeFila(f);
	inserir(f, 4);
	imprimeFila(f);
	inserir(f, 230);
	imprimeFila(f);
	inserir(f, 10);
	imprimeFila(f);
	inserir(f, 20);
	imprimeFila(f);

	remover(f);
	remover(f);
	remover(f);
	remover(f);

	imprimeFila(f);

	printf("inicio: %d fim: %d max: %d\n", f->inicio, f->fim, f->max);

	// printf("%d\n\n", compFila(*f));

	inserir(f, 5);

	imprimeFila(f);
	inserir(f, 230);
	imprimeFila(f);

	printf("inicio: %d fim: %d max: %d\n",f->inicio, f->fim, f->max );
	inserir(f, 5);
	imprimeFila(f);

	inserir(f, 29873);

	printf("%d\n", f->fim);
	imprimeFila(f);

	inserir(f, 111);
	imprimeFila(f);

	inserir(f, 221);
	imprimeFila(f);

	inserir(f, 333);
	imprimeFila(f);

	inserir(f, 41141);
	imprimeFila(f);

	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);
	inserir(f, 41141);

	inserir(f, 5);

	inserir(f, 5);

	inserir(f, 5);

	inserir(f, 5);
	imprimeFila(f);



	return 0;
}