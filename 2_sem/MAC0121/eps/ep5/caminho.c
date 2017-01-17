#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "filapos.h"
#include "caminho.h"

int temVizinhos(pos posicao, char** aux, char color){

	if (posicao.y - 1 >= 0 && aux[posicao.x][posicao.y - 1] == color)
		return 1;
	else if (posicao.y - 1 >= 0 && posicao.x + 1 < 14 &&
	 aux[posicao.x + 1][posicao.y - 1] == color)
		return 1;
	else if (posicao.x + 1 < 14 && aux[posicao.x + 1][posicao.y] == color)
		return 1;
	else if (posicao.y + 1 < 14 && aux[posicao.x][posicao.y + 1] == color)
		return 1;
	else if (posicao.y + 1 < 14 && posicao.x - 1 >= 0 && 
		aux[posicao.x - 1][posicao.y + 1] == color)
		return 1;
	else if (posicao.x - 1 >= 0 && aux[posicao.x - 1][posicao.y] == color)
		return 1;
	else 
		return 0;
}

pos pegaVizinho(pos posicao, char** aux, char color){

	pos viz;

	if (posicao.y - 1 >= 0 && aux[posicao.x][posicao.y - 1] == color){
		aux[posicao.x][posicao.y - 1] = 'v';
		viz.x = posicao.x;
		viz.y = posicao.y - 1;
	}
	else if (posicao.y - 1 >= 0 && posicao.x + 1 < 14 &&
	 aux[posicao.x + 1][posicao.y - 1] == color){
		aux[posicao.x + 1][posicao.y - 1] = 'v';
		viz.x = posicao.x + 1;
		viz.y = posicao.y - 1;
	}
	else if (posicao.x + 1 < 14 && aux[posicao.x + 1][posicao.y] == color){
		aux[posicao.x + 1][posicao.y] = 'v';
		viz.x = posicao.x + 1;
		viz.y = posicao.y;
	}
	else if (posicao.y + 1 < 14 && aux[posicao.x][posicao.y + 1] == color){
		aux[posicao.x][posicao.y + 1] = 'v';
		viz.x = posicao.x;
		viz.y = posicao.y + 1;
	}
	else if (posicao.y + 1 < 14 && posicao.x - 1 >= 0 && 
		aux[posicao.x - 1][posicao.y + 1] == color){
		aux[posicao.x - 1][posicao.y + 1] = 'v';
		viz.x = posicao.x - 1;
		viz.y = posicao.y + 1;
	}
	else {
		aux[posicao.x - 1][posicao.y] = 'v';
		viz.x = posicao.x - 1;
		viz.y = posicao.y;
	}

	return viz;
}
int checaCaminho(char** tab, int lado, char color){

	char **aux;
	fila* caminho;
	pos posicao, vizinho;

	aux = copiaHex(tab);

	caminho = criaFila(14*7);

	if (color == 'b'){
		posicao.x = lado;
		posicao.y = 0;
	}
	else {
		posicao.x = 0;
		posicao.y = lado;
	}

	insereFila(caminho, posicao);
	aux[posicao.x][posicao.y] = 'v';

	while ((color == 'b' && posicao.y != 13) || 
		(color == 'p' && posicao.x !=13)){

		if (filaVazia(*caminho)){
			return 0;
		}

		posicao = removeFila(caminho);

		while (temVizinhos(posicao, aux, color)){
			vizinho = pegaVizinho(posicao, aux, color);
			insereFila(caminho, vizinho);
		} 
	}

	free(caminho);
	liberaHex(aux);

	return 1;
}

int checaVencedor(char **tab, char color){

	int i, j, res;

	res = 0;

	if (color == 'p'){
		for (j = 0; j < 14 && res == 0; j++){
			if (tab[0][j] == color){
				res = checaCaminho(tab, j, color);
			}
			if (res == 1)
				printf("preto ganhou.\n");
		}
	}
	else {
		for (i = 0; i < 14 && res == 0; i++){
			if (tab[i][0] == color){
				res = checaCaminho(tab, i, color);
			}
			if (res == 1)
				printf("branco ganhou.\n");
		}
	}

	return res;
}