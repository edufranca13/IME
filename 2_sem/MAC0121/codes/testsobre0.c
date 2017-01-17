#include <stdio.h>

int funcaoteste(){
	return 0;
}


int main() {

	printf("em C o valor 0 é:");

	if (0) printf("verdadeiro\n");
	else printf("falso\n");

	if (funcaoteste()) 
		printf("correto\n");

	return 0;
}