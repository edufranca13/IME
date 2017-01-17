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

	printf("configuração inicial\n\n");
	imprimeMatriz(tab, m, n);

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

	printf("configuração final\n\n");
	imprimeMatriz(tab, m, n);
	printf("sequência de passos\n\n");
	imprimePilha(memoria);
	destroiPilha(memoria);
	destroiMatriz(tab, m);

	return;
}

int main() {

	// int **tab;
	// tab = criaMatriz(6,6);
	// iniciaMatriz(tab, 6, 6);

	// tab[2][3] = -1;

	// resta(tab, 6, 6);

	// int **tab;

	// tab = criaMatriz(7,7);
	// iniciaMatriz(tab, 7, 7);

	// tab[0][0] = 0;
	// tab[0][1] = 0;
	// tab[1][0] = 0;
	// tab[1][1] = 0;

	// tab[0][5] = 0;
	// tab[0][6] = 0;
	// tab[1][5] = 0;
	// tab[1][6] = 0;

	// tab[5][0] = 0;
	// tab[5][1] = 0;
	// tab[6][0] = 0;
	// tab[6][1] = 0;

	// tab[5][5] = 0;
	// tab[5][6] = 0;
	// tab[6][5] = 0;
	// tab[6][6] = 0;

	// tab[3][3] = -1;

	// resta(tab, 7, 7);

	// int **tab;

	// tab = criaMatriz(3,3);
	// iniciaMatriz(tab, 3, 3);

	// tab[0][1] = 0;
	// tab[0][2] = 0;
	// tab[2][0] = -1;
	// tab[2][1] = 0;
	// tab[2][2] = 0;

	// resta(tab, 3, 3);

	return 0;

}