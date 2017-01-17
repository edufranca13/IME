//testar caso impossivel
//falta considerar a diagonal direita
//falta remover a vertical e horizontal
//fazer outro loop mais externo para imprimir todas as configuracoes possives
#include <stdio.h>
#include <stdlib.h>

typedef struct {

	int x;
	int y;

} pos;

typedef struct reg {

	pos* v;
	int topo;
	int max;

}pilha;

int** criaMatriz(int m, int n){

	int** matriz = malloc(sizeof(int*)*m);
	int i;
	for (i = 0; i < m; i++)
		matriz[i] = malloc(sizeof(int)*n);

	return matriz;
}

void iniciaMatriz(int** matriz, int m, int n){
	
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			matriz[i][j] = 0;	
}

void imprimeMatriz(int **matriz, int m, int n){

	int i, j;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++)
			printf("%d ", matriz[i][j]);
		printf("\n");
	}
		printf("\n");
}
pilha* criaPilha(int max){

	pilha* p = malloc(sizeof(pilha));
	p->v = malloc(sizeof(pos)*max);

	p->max = max;
	p->topo = 0;

	return p;
}

int pilhaCheia(pilha p){
	
	return (p.topo == p.max - 1);
}

int pilhaVazia(pilha p){

	return (p.topo == 0);
}
void realocaPilha(pilha* p){
	
	pos* w = malloc(sizeof(pos)*2*p->topo);
	
	int i;
	for (i = 0; i < p->topo; i++)
		w[i] = p->v[i];
	
	free(p->v);
	p->v = w;
	p->max = 2*p->max;
	
}
void empilha(pilha* p, int x, int y){
	
	pos t;
	t.x = x;
	t.y = y;

	if (pilhaCheia(*p))
		realocaPilha(p);
	
	p->v[p->topo++] = t;
}

pos desempilha(pilha* p){
	
	if (pilhaVazia(*p))
		exit(1);

	pos p1;
	p1 = p->v[--p->topo];
	
	return p1;
}

void imprimePilha(pilha p){
	
	int i;
	for (i = 0; i < p.topo; i++)
		printf("%d: %d %d\n", i, p.v[i].x, p.v[i].x);
}

int posicaoLivre(int** matriz, int x, int y){

	int i;
	int j;

	for (i = 0; i <= x; i++)
	       if (matriz[i][y] == 1)
	       		return 0;

	for (j = 0; j <= x; j++)
	       if (matriz[x][j] == 1)
	       		return 0;

	//diagonal esquerda
	for (i = 0, j = 0; x - i >= 0 && y - j >= 0;i++, j++){
		if (matriz[x-i][y-j] == 1)
			return 0;
	}
	return 1;	

}
int main(int argc, char* const argv[]){

	int n = atoi(argv[1]);
	
	pilha* p = criaPilha(2*n);
	
	int** matriz = criaMatriz(n, n);

	iniciaMatriz(matriz, n, n);

	int i = 0;
	int j = 0;
	pos temp;

	while (i < n){
	
		if (posicaoLivre(matriz, i, j) && j < n){
			matriz[i][j] = 1;
			empilha(p, i, j);
			i++;
			j = 0;
			imprimeMatriz(matriz, n, n);
		}

		else {
			j++;
			if (j >= n){
				imprimeMatriz(matriz, n, n);
				temp = desempilha(p);
				i = temp.x;
				j = temp.y;
				matriz[i][j] = 0;
				j++;
			}
		}
	}	
	
	return 0;
}
