#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filapos.h"

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

void estrategia(char ** tab, char color){

	int x, y;
	if (color == 'b'){
		x = 6;
		y = 0;

		while (tab[x][y] != '-'){
			y = y + 1;
			if (y == 14){
				y = 0;
				x++;
			}
			if (x == 14)
				x = 0;
		}
	}
	
	else {
		x = 0;
		y = 6;
	
		while (tab[x][y] != '-'){
			x = x + 1;
			if (x == 14){
				x = 0;
				y++;
			}
			if (y == 14)
				y = 0;
		}
	}
	printf("%d %d\n", x, y);
	tab[x][y] = color;
}

int jogadaValida(char **tab, int x, int y){

	if (x < 0 || x > 13 || y < 0 || y > 13)
		return 0;
	if (tab[x][y] != '-')
		return 0;
	else 
		return 1;
}

int main(int argc, char const *argv[])
{
	
	char **tab;
	char color1, color2, tColor;
	int x, y, d, move;

	tab = criaHex();
	iniciaHex(tab);
	srand(time(NULL));

	if (strcmp(argv[1], "b") == 0) {
		color1 = 'b';
		color2 = 'p';
	}
	else if (strcmp(argv[1], "p") == 0) {
		color1 = 'p';
		color2 = 'b';
	}
	else {
		printf("Opção inválida.\n");
		exit(1);
	}

	d = 0;
	if (argc == 3 && strcmp(argv[2], "d") == 0){
		d = 1;
	}

	move = 0;
	while (!checaVencedor(tab, color1)){

		if (color1 == 'p' && move == 0){}
		else {
			estrategia(tab, color1);
			if (d) imprimeHex(tab);
			if (checaVencedor(tab, color1))
				return 0;
		}
		
		scanf("%d %d", &x, &y);

		if (move == 0 && tab[x][y] == color1){
	
			tab[x][y] = color2;
			
			tColor = color1;
			color1 = color2;
			color2 = tColor;
			
			if (d) imprimeHex(tab);
		}

		while (move != 0 && !jogadaValida(tab, x, y)){
			printf("jogada inválida.\n");
			scanf("%d %d", &x, &y);
		}
		
		tab[x][y] = color2;
		if (d) imprimeHex(tab);
		move++;
	}

	liberaHex(tab);

	return 0;
}
