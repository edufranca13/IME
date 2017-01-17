#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filapos.h"
#include "tabuleiro.h"
#include "caminho.h"

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
