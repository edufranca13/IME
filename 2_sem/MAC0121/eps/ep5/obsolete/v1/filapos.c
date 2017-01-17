typedef struct pos {

	int x;
	int y;

} pos;

typedef struct {

	pos *v;
	int max;
	int fim;
	int inicio;

} fila;

fila *criaFila(int max){

	fila *f;

	f = malloc(sizeof(fila));
	f->v = malloc(max*sizeof(pos));
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

	pos *w;

	w = malloc(novoMax*sizeof(pos));

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

pos removeFila(fila *f) {

	pos x;
	if (filaVazia(*f)){
		printf("erro");;
		exit(1);
	}
	x = f->v[f->inicio];
	f->inicio = (f->inicio + 1) % f->max;

	return x;
}

void insereFila(fila *f, pos x){

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
			printf("x: %d y: %d\n", (f->v[i]).x, (f->v[i]).y);
		for (i = 0; i < f->fim; i++)
			printf("x: %d y: %d\n", (f->v[i]).x, (f->v[i]).y);
	}
	else
		for (i = f->inicio; i < f->fim; i++)
			printf("x: %d y: %d\n", (f->v[i]).x,(f->v[i]).y);
	printf("\n");
}