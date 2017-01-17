#include <stdio.h>
#include <stdlib.h>
#include "tuple.h"

tuple *createTuple(int *numbers, int n){

	tuple *v;
	v = malloc(sizeof(tuple)*n);

	int i;
	for (i = 0; i < n; i++){
		v[i].value = numbers[i];
		v[i].index = i;
	}
	return v;
}

void printTuple(tuple *v, int n){

	int i;
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d: %4d\n", v[i].index, v[i].value);
	printf("\n");
}