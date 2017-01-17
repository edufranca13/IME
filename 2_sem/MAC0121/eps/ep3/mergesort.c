#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void printv(int *v, int inicio, int fim){
	int i;
	for (i = inicio; i < fim; i++)
		printf("%d ", v[i]);
	printf("\n");
}


void merge(int *v, int inicio, int meio, int fim){

	int i = inicio;
	int j = meio;

	int *w;
	w = malloc(sizeof(int)*(fim-inicio));

	int k = 0;

	while (i < meio && j < fim){

		if (v[i] <= v[j])
			w[k++] = v[i++];
		else
			w[k++] = v[j++];
	}

	while (i < meio)
		w[k++] = v[i++];
	while (j < fim)
		w[k++] = v[j++];

	int it;
	for (it = inicio; it < fim; it++)
		v[it] = w[it-inicio];

	free(w);
}


void mergesort(int *v, int inicio, int fim){

	if (inicio < fim - 1){
		int meio = (inicio + fim) / 2;
		mergesort(v, inicio, meio);
		mergesort(v, meio, fim);
		merge(v, inicio, meio, fim);
	}
}