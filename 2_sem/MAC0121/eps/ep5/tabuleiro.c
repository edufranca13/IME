#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

char **criaHex(){

	char **tab;
	int i;
	
	tab = malloc(14*sizeof(char*));
	
	for (i = 0; i < 14; i++)
		tab[i] = malloc(14*sizeof(char));

	return tab;
}

void iniciaHex(char **tab){

	int i, j;
	for (i = 0; i < 14; i++)
		for (j = 0; j < 14; j++)
			tab[i][j] = '-';
}

void liberaHex(char** tab){

	int i;
	for (i =0; i < 14; i++)
		free(tab[i]);
	free(tab);
}

char** copiaHex(char** tab){

	char** aux;
	int i, j;

	aux = criaHex();
	iniciaHex(aux);

	for (i = 0; i < 14; i++)
		for (j = 0; j < 14; j++)
			aux[i][j] = tab[i][j];

	return aux;
}

void imprimeHex(char **tab){

	int i, j;
	for (i = 0; i < 14; i++){
		fprintf(stderr, "%*c", i+1, ' ');
		for (j = 0; j < 14; j++)
			fprintf(stderr, "%c ", tab[i][j]);
		fprintf(stderr, "\n");
	}
}