#include <stdio.h>

int main(){

	int v[100];

	for(int i = 0; i < 100; i++){
		v[i] = 2*i;
	}

	int *pz;

	pz = v;

	printf("%d, %d\n", v[0], *pz);

}