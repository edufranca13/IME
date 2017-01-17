#include <stdio.h>

void troca(int *pa, int *pb){
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}


int maior(int *pm, int *pn){
	if(*pm > *pn){
		troca(pm, pn);
	}
	return *pn;
}


int main(){

	int a = 20;
	int b = 10;

	int c = 0;

	printf("antes -----> a: %d, b: %d, c: %d\n", a, b, c);

	c = maior(&a, &b);

	printf("depois -----> a: %d, b: %d, c: %d\n", a, b, c);
}