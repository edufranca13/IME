#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "pilha.c"
#include "matrizes.c"
#include "matrizes.h"

int posLivre(int **tab, int l, int c, int n){

	int i;
	// for (i = 0; i < n; i++)
	// 	if (tab[l][i] == 1) return 0;
	// for (i = 0; i < n; i++)
	// 	if (tab[i][c] == 1) return 0;
	for (i = 0; l+i < n && c+i < n; i++)
		if (tab[l+i][c+i] == 1) return 0;
	for (i = 0; l-i >= 0 && c-i >= 0; i++)
		if (tab[l-i][c-i] == 1) return 0;
	for (i = 0; l+i < n && c-i >= 0; i++)
		if (tab[l+i][c-i] == 1) return 0;
	for (i = 0; l-i >= 0 && c+i < n; i++)
		if (tab[l-i][c+i] == 1) return 0;
	
	return 1;
}

void nBispos(int n){

	int atual, col, ok, i, j;
	int **tab;
	pilha *bispos;

	tab = criaMatriz(n, n);

	if (tab == NULL){
		printf("Memória insuficiente para a alocação do tabuleiro\n");
		return;
	}
	
	else {
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				tab[i][j] = 0;
		}

		bispos = criaPilha(n);
		atual = 0;
		col = 0;

		while (atual < n){

			ok = 0;

			while (col < n && ok == 0) {

				if (posLivre(tab, atual, col, n)){
					ok = 1;
				}
				else {
					col++;
				}
			}

			if (ok == 1){
				empilha(bispos, col);
				tab[atual][col] = 1;
				col = 0;
				atual++;
			}

			else {
				if (pilhaVazia(*bispos)){
					printf("Problema sem solução");
					destroiMatriz(tab, n);
					destroiPilha(bispos);
					return;
				}

				col = desempilha(bispos);
				atual--;
				tab[atual][col] = 0;
				col++;
			}
		}

		imprimeMatriz(tab, n, n);
		destroiMatriz(tab, n);
		destroiPilha(bispos);
		return;
	}


	int main() {


	nBispos(5);

	return 0;
	}