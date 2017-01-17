#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	
	FILE *entrada;
	entrada = fopen("texto.txt", "r");
	char *c = malloc(1024);

	if (entrada == NULL){
		printf("erro - arquivo não encontrado\n");
		exit(1);
	}
	else {
		while (fscanf(entrada, "%s", c) == 1)
			printf("%s\n", c);
	}

	fclose(entrada);
	
	return 0;
}