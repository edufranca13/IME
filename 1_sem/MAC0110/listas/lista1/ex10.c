#include <stdio.h>

int main(){

	int v[100];

	for(int i = 0; i < 100; i++){
		v[i] = 2*i;
	}

	int *pz;

	pz = v;

	for (int j=1; j <= 10; j++){

		printf("%d\t", *pz);
		pz = v + j;
	}

}