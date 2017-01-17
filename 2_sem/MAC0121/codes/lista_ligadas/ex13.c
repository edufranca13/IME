#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg *prox;

} celula;


int main(void)
{
	printf("sizeof (celula) = %lu \n", sizeof(celula));
	return 0;
}