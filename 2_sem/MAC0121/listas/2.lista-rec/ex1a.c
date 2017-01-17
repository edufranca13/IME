#include <stdio.h>
#include <stdlib.h>

int min(int v[], int n) {

	if (n  == 1)
		return v[0];

	if (v[n-1] < min(v, n-1))
		return v[n-1];
	else
		return min(v, n-1);

}

int main(int argc, char* const argv[]){

	int v[] = {2, 4, 6, 3, 1, 2, 3, 6, 3};
	int minimo = min(v, 9);

	printf("%d\n", minimo);


	return 0;
}

