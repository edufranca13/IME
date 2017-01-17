#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll2.c"

int main(int argc, char const *argv[])
{
	
	FILE *entrada;
	entrada = fopen(argv[1], "r");

	char *palavra;
	palavra = malloc(1024);

	apontador p = NULL;

	while (fscanf(entrada, "%s", palavra) == 1){
		p = insereOrdenado(p, palavra);
	}

	mergeSort(&p);

	imprimeLista(p);

	fclose(entrada);

	return 0;
}