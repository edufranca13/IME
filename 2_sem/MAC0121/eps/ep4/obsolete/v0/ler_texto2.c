#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vec.c"

int main(int argc, char const *argv[])
{
	
	FILE *entrada;
	entrada = fopen(argv[1], "r");

	char *palavra;
	palavra = malloc(1024);

	vetor *p = criaVetor(100);

	while (fscanf(entrada, "%s", palavra) == 1){
		insereDesordenadoVec(p, palavra);
	}

	mergeSort(p, 0, p->ultimo);

	imprimeVetor(p);

	fclose(entrada);

	return 0;
}