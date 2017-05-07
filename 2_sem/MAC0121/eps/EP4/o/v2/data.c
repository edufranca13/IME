#include "data.h"
#include <stdlib.h>
#include <string.h>

char *cP(char *palavra){

	char *novaPalavra;
	int i, c, j, len;
	novaPalavra = malloc(1024);

	i = 0;
	c = palavra[i];

	if (c >= 48 && c <= 57){
		while (c >= 48 && c <= 57)
			c = palavra[i++];
		i--;
	}

	j = 0;
	len = strlen(palavra);

	for (; i < len; i++)
		novaPalavra[j++] = palavra[i];
	
	novaPalavra[j] = '\0';

	strcpy(palavra, novaPalavra);
	free(novaPalavra);

	return palavra;
}

int compareO(const void * a, const void * b) {
    return - (*(data*)a).contador + (*(data*)b).contador;
}

int compareA(const void * a, const void * b) {
    return strcmp((*(data*)a).palavra, (*(data*)b).palavra);
}
