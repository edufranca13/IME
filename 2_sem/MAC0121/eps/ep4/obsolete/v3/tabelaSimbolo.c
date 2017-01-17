#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "VDVO.h"
#include "LDLO.h"
#include "tabelaSimbolo_VD.h"
#include "tabelaSimbolo_VO.h"
#include "tabelaSimbolo_LD.h"
#include "tabelaSimbolo_LO.h"
#include "tabelaSimbolo_AB.h"

int main(int argc, char const *argv[])
{
	clock_t inicio, fim;
	double tempo;
	FILE *entrada;
	char *palavra;

	inicio = clock();

	entrada = fopen(argv[1], "r");

	palavra = malloc(1024);

	if (argc != 4){
		printf("Argumentos esperados: <texto.txt> <tipo_estrutura> <ordenacao> \n");
		exit(1);
	}

	if (strcmp(argv[2],"VD") == 0 || strcmp(argv[2], "VO") == 0){
		vetor *p = criaV(5);
		if (strcmp(argv[2],"VD") == 0)
			while (fscanf(entrada, "%s", palavra) == 1)
				p = insereDesordenadoV(p, cP(palavra));
		else
			while (fscanf(entrada, "%s", palavra) == 1)
				p = insereOrdenadoV(p, cP(palavra));
			
		if (strcmp(argv[3], "O") == 0)
			qsort(p->data, p->ultimo, sizeof(p->data[0]), compareO);
		else if (strcmp(argv[3], "A") == 0 && strcmp(argv[2], "VD") == 0)
			qsort(p->data, p->ultimo, sizeof(p->data[0]), compareA);

		imprimeV(p);
		free(p);
	}

	else if (strcmp(argv[2],"LD") == 0 || strcmp(argv[2], "LO") == 0){
		apontador p = NULL;
		if (strcmp(argv[2],"LD") == 0)
			while (fscanf(entrada, "%s", palavra) == 1)
				p = insereDesordenadoL(p, cP(palavra));
		else
			while (fscanf(entrada, "%s", palavra) == 1)
				p = insereOrdenadoL(p, cP(palavra));
			
		if (strcmp(argv[3], "O") == 0)
			sortLL(p, argv[3]);
		else if (strcmp(argv[3], "A") == 0 && strcmp(argv[2], "LD") == 0)
			sortLL(p, argv[3]);

		imprimeL(p);
		free(p);
	}

	else if (strcmp(argv[2], "AB") == 0){
		apontadorA p = NULL;
		while (fscanf(entrada, "%s", palavra) == 1)
			p = insereAB(p, cP(palavra));

		if (strcmp(argv[3], "O") == 0){
			sortAB(p);
		}
		
		imprimeEmOrdem(p);
		free(p);
	}

	fclose(entrada);

	fim = clock();
	tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

	printf("\ntempo consumido: %.2f\n", tempo);

	return 0;
}