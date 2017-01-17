#include <stdlib.h>
#include <stdio.h>
#include "matrizes.h"

int posLivre(int **tab, int l, int c, int n){

	int i;
	for (i = 0; i < n; i++)
		if (tab[l][i] == 1) return 0;
	for (i = 0; i < n; i++)
		if (tab[i][c] == 1) return 0;
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

int nRainhasR(int n, int **tab, int atual){

	int col;
	if (n == atual)
		return 1;

	for (col = 0; col < n; col++)
		if (posLivre(tab, atual, col, n)){
			tab[atual][col] = 1;
			if (nRainhasR(n, tab, atual+1))
				return 1;
			tab[atual][col] = 0;
		}
	return 0;
}

int main(){

	int **tab;
	tab = criaMatriz(8, 8);
	iniciaMatriz(tab, 8,8);

	int x;
	x = nRainhasR(8, tab, 0);

	imprimeMatriz(tab, 8, 8);

	return 0;
}