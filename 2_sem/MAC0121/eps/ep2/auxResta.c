#include "auxResta.h"
#include "matriz.h"

int ePeca(int **tab, int l, int c){

	if (tab[l][c] == 1)
		return 1;
	else
		return 0;
}

int podeComer(int **tab, int l, int c, int mov, int m, int n){

	switch(mov){

		case 1: 
			if (c + 1 < n && c + 2 < n && tab[l][c+1] == 1 && tab[l][c+2] == -1)
				return 1;
			else return 0;

		case 2: 
			if (l + 1 < m && l + 2 < m && tab[l+1][c] == 1 && tab[l+2][c] == -1)
				return 1;
			else return 0;

		case 3: 
			if (c - 1 >= 0 && c - 2 >= 0 && tab[l][c-1] == 1 && tab[l][c-2] == -1)
				return 1;
			else return 0;

		case 4: 
			if (l - 1 >= 0 && l - 2 >= 0 && tab[l-1][c] == 1 && tab[l-2][c] == -1)
				return 1;
			else return 0;

		default:
			return 0;
	}

	return 0;
}

void come(int **tab, int l, int c, int mov){

	tab[l][c] = -1;

	switch(mov){

		case 1: 
			tab[l][c+1] = -1;
			tab[l][c+2] = 1;
			break;
		case 2: 
			tab[l+1][c] = -1;
			tab[l+2][c] = 1;
			break;
		case 3: 
			tab[l][c-1] = -1;
			tab[l][c-2] = 1;
			break;
		case 4: 
			tab[l-1][c] = -1;
			tab[l-2][c] = 1;
			break;
	}
}

void volta (int **tab, int l, int c, int mov){

	tab[l][c] = 1;

	switch(mov){

		case 1: 
			tab[l][c+1] = 1;
			tab[l][c+2] = -1;
			break;
		case 2: 
			tab[l+1][c] = 1;
			tab[l+2][c] = -1;
			break;
		case 3: 
			tab[l][c-1] = 1;
			tab[l][c-2] = -1;
			break;
		case 4: 
			tab[l-1][c] = 1;
			tab[l-2][c] = -1;
			break;
	}
}

int **inverteTab(int **tab, int m, int n){

	int **tabi, i, j;

	tabi = criaMatriz(m, n);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++){
			if (tab[i][j] == 1)
				tabi[i][j] = -1;
			if (tab[i][j] == -1)
				tabi[i][j] = 1;
			if (tab[i][j] == 0)
				tabi[i][j] = 0;
		}

	return tabi;
}

int contaUns(int **tab, int m, int n, int a){

	int i, j, cont;
	cont = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if(tab[i][j] == a)
				cont++;

	return cont;
}
