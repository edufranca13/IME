#include <stdio.h>
#include <stdlib.h>
#include "tuple.h"
#include "mergesort.h"
#include "binarysearchfo.h"

/*relaciona os indices da tupla original com o indice onde ele deveria estar*/
void makeTable(int *table, tuple *v, tuple *sorted, int n){

	int j;
	int i;
	for (i = 0; i < n; i++){
		int right_ind = binarysearchfo(sorted, 0, n, v[i].value);
		for (j = 0; j < i; j++)
			if (table[j] == right_ind)
				right_ind++;
		table[i] = right_ind;
	}
	// for (i = 0; i < n; i++)
	// 	printf("%d ", table[i]);
	// printf("\n");
}

/*avalia a paridade do indice da tupla e do indice de onde ele deveria*/
int checkParity(tuple *v, int *table, int counter){

	if (counter % 2 == 0 && table[v[counter].index] % 2 == 0 || 
		counter % 2 != 0 && table[v[counter].index] % 2 != 0)
		return 0;
	else if (counter % 2 == 0 && table[v[counter].index] % 2 != 0)
		return 1;
	else if (counter % 2 != 0 && table[v[counter].index] % 2 == 0)
		return 2;
}

int moveback(int index, int n){

	int res;
	res = index - 2;
	if (res < 0)
		return (n + index - 2) % n;
	else
		return res;
}

void swap(tuple v[], int i, int j){

	printf("%d\n", i, j);
	tuple temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void sort(tuple v[], int n){

	int i; 
	int j;
	for (i = n - 2; i > 0; i -= 2)
		for (j = 1; j < i; j += 2)
			if (v[j].value > v[j+2].value)
				swap(v, j, j+2);
	
	for (i = n - 2; i > 0; i -= 2)
		for (j = 0; j < i; j += 2)
			if (v[j].value > v[j+2].value)
				swap(v, j, j+2);
}

/*organizar um vetor circular numbers[] através de permutações de números em torno de um número
intermediário */
void trSort(int numbers[], int n){

	tuple *v;
	v = createTuple(numbers, n);

	int *w;
	w = malloc(sizeof(int)*n);

	int i;
	for (i = 0; i < n; i++)
		w[i] = numbers[i];

	mergesort(w, 0, n);

	tuple *sorted;
	sorted = createTuple(w, n);

	int *table;
	table = malloc(sizeof(int)*n);

	makeTable(table, v, sorted, n);

	int counter = 0;
	int next;

	//loop para encontrar um par de indices com paridades trocadas e fazer a troca
	while (counter < n){

		int typeParity = checkParity(v, table, counter);

		if (!typeParity)
			counter++;
		else {
			int next = (counter + 2) % n;
			while (checkParity(v, table, next) == typeParity || checkParity(v, table, next) == 0){
				next = (next + 2) % n;
				if (next == counter){
					printf("Nao e possivel\n");
					return;
				}
			}
			int aux = counter;
			while (aux != next){
				swap(v, aux, (aux + 2) % n);
				aux = (aux + 2) % n;
			}
			next = moveback(next, n);
			while (next != counter){
				swap(v, next, moveback(next, n));
				next = moveback(next, n);
			}
		}
	}
	sort(v, n);

	printv(v, n);
}

int main(int argc, char const *argv[]){

	FILE *entrada;

	entrada = fopen(argv[1], "r");

	if (entrada == NULL)
		exit(0);

	int n, i;
	fscanf(entrada, "%d", &n);

	int numbers[n];

	for (i = 0; i < n; i++)
		fscanf(entrada, "%d", &numbers[i]);

	trSort(numbers, n);

	return 0;
	}