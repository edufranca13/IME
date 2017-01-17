#include <stdio.h>

int maior(int *pm, int *pn){
	int temp;
	if(*pm > *pn){
		temp = *pm;
		*pm = *pn;
		*pn = temp;
	}
	return *pn;
}


int main(){

	int a = 20;
	int b = 10;

	int c = 0;

	printf("antes -----> a: %d, b: %d, c: %d\n", a, b, c);

	c = maior(&a, &b);

	printf("depois ------> a: %d, b: %d, c: %d\n", a, b, c);

	int *pa;
	int *pb;

	pa = &a;
	pb = &b;

	c = maior(pa, pb);

	printf("depois ------> a: %d, b: %d, c: %d\n", a, b, c);

	return 0;
}