#include <stdio.h>

int main(){

	int v[100];

	for(int i = 0; i < 100; i++){
		v[i] = 2*i;
	}

	int *pz;
	int *pw;

	pz = v + 1;
	pw = &v[1];

	printf("%d, %d, %d, %p, %p\n", v[1], *pz, *pw, pz, pw);

}