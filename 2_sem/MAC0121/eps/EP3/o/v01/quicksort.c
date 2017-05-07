#include <stdio.h>

int separa(float v[], int inicio, int fim){

	int i = inicio + 1;
	int j = fim;

	float temp;
	float c = v[inicio];
	while (i <= j){

		if (v[i] <= c)
			++i;
		else if (v[j] > c)
			--j;
		else {
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			++i;
			--j;
		}
	}
	v[inicio] = v[j];
	v[j] = c;
	return j;
}

void quicksort(float v[], int inicio, int fim){

	int j;

	if (inicio < fim){
		j = separa(v, inicio, fim);
		quicksort(v, inicio, j - 1);
		quicksort(v, j + 1, fim);
	}
}