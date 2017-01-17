#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "auxResta.h"
#include "pilha.h"

void resta(int **tab, int m, int n){

	pilha *memoria;
	pos atual;
	int ok, mexeu;

	int **tabInvertido;

	tabInvertido = inverteTab(tab, m, n);

	// printf("configuração inicial\n\n");
	// imprimeMatriz(tab, m, n);

	memoria = criaPilha(m*n);

	atual.lin = atual.col = 0;
	atual.mov = 1;

	mexeu = 1;

	while (!comparaMatrizes(tab, tabInvertido, m, n)){

		ok = 0;

		while(ePeca(tab, atual.lin, atual.col) && atual.mov <= 4 && ok == 0){

			if (podeComer(tab, atual.lin, atual.col, atual.mov, m, n)) {
				ok = 1;
			}
			else 
				atual.mov++;
		}

		if (ok == 1){
			empilha(memoria, atual);
			come(tab, atual.lin, atual.col, atual.mov);
			mexeu = 1;
		}

		else {

			if (pilhaVazia(*memoria) && atual.lin == m - 1 && atual.col == n - 1){
				printf("Impossível");
				destroiPilha(memoria);
				destroiMatriz(tab, m);
				return;
			}

			if (mexeu == 0 && atual.lin == m - 1 && atual.col == n - 1) {
				atual = desempilha(memoria);
				volta(tab, atual.lin, atual.col, atual.mov);
				atual.mov++;
			}

			else {
				atual.mov = 1;
				atual.col++;

				if (atual.col == n){
					atual.col = 0;
					atual.lin++;
				}

				if(atual.lin == n){
					atual.lin = 0;
					mexeu = 0;
				}
			}
		}
	}

	// printf("configuração final\n\n");
	// imprimeMatriz(tab, m, n);
	// printf("sequência de passos\n\n");
	imprimePilha(memoria);
	destroiPilha(memoria);
	destroiMatriz(tab, m);

	return;
}

int main(int argc, char const *argv[]){

	FILE *entrada;
	entrada = fopen(argv[1], "r");

	if (entrada == NULL)
		exit(0);

	int m, n, t, i, j;
	int **tab;

	fscanf(entrada, "%d", &m);

	fscanf(entrada, "%d", &n);

	tab = criaMatriz(m, n);

	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			fscanf(entrada, "%d", &t);
			tab[i][j] = t;
		}
	}

	resta(tab, m, n);

	return 0;

}