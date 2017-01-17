#include <stdio.h>

void imp(int *pos, int n){
	for (int j=1; j <= n; j++){
		printf("%d\t", *pos);
		pos = pos + 1;
	}
}


int main(){

	int v[100];

	for(int i = 0; i < 100; i++){
		v[i] = 2*i;
	}

	int *pz;

	pz = v;

	imp(pz, 10);
}