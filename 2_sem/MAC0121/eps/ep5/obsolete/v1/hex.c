#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filapos.c"

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
		printf("%*c", i+1, ' ');
		for (j = 0; j < 14; j++)
			printf("%c ", tab[i][j]);
		printf("\n");
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
	else if (posicao.x - 1 >= 0 && aux[posicao.x - 1][posicao.y] == color){
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

	printf("celula x: %d y: %d\n", posicao.x, posicao.y);

	while ((color == 'b' && posicao.y != 13) || 
		(color == 'p' && posicao.x !=13)){

		if (filaVazia(*caminho)){
			printf("Sem caminho\n");
			return 0;
		}

		posicao = removeFila(caminho);

		while (temVizinhos(posicao, aux, color)){
			vizinho = pegaVizinho(posicao, aux, color);
			insereFila(caminho, vizinho);
		} 

		imprimeHex(aux);
	}

	printf("retornou 1 do checaCaminho\n");

	return 1;
}

int checaVencedor(char **tab, char color){

	int i, j, res;

	res = 0;

	printf("checando Vencedor\n" );
	if (color == 'p'){
		for (j = 0; j < 14 && res == 0; j++){
			printf("tab[0][%d] -> %c\n", j, tab[0][j]);
			if (tab[0][j] == color){
				res = checaCaminho(tab, j, color);
			}
		}
	}
	else {
		for (i = 0; i < 14 && res == 0; i++){
			printf("tab[%d][0] -> %c\n", i, tab[i][0]);
			if (tab[i][0] == color){
				res = checaCaminho(tab, i, color);
			}
		}
	}

	return res;
}

void estrategia(char ** tab, char color){

	int x, y;
	if (color == 'b'){
		x = 6;
		y = 0;
		printf("%d %d\n", x, y);
	
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
		printf("%d %d\n", x, y);
	
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
	int x, y, d;

	tab = criaHex();
	iniciaHex(tab);
	srand(time(NULL));

	if (strcmp(argv[1], "b") == 0) {
		printf("Usuario joga com as pretas.\n");
		color1 = 'b';
		color2 = 'p';
	}
	else if (strcmp(argv[1], "p") == 0) {
		printf("Usuario joga com as brancas.\n");
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

	int move = 0;
	while (!checaVencedor(tab, color1)){

		if (color1 == 'p' && move == 0){}
		else {
			printf("meu movimento: \n");
			estrategia(tab, color1);
			if (d) imprimeHex(tab);
		}
		
		printf("entre com a jogada: \n");
		scanf("%d %d", &x, &y);

		if (move == 0 && tab[x][y] == color1){
			printf("jogador optou por pie rule\n");
			tab[x][y] = color2;
			
			tColor = color1;
			color1 = color2;
			color2 = tColor;
			
			if (d) imprimeHex(tab);
		}

		while (move != 0 && !jogadaValida(tab, x, y)){
			printf("jogada inválida. entre com a jogada: \n");
			scanf("%d %d", &x, &y);
		}
		
		tab[x][y] = color2;
		if (d) imprimeHex(tab);
		move++;
	}

	return 0;
}