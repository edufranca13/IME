#include “binarySearch.h”

int binarySearch(float v[], int inicio, int fim, float x){

	if (inicio > fim - 1)
		return -1;
	else{
		int meio = (inicio + fim)/2;
		if (x > v[meio])
			return binarySearch(v, meio, fim, x);
		else if (x < v[meio])
			return binarySearch(v, inicio, meio, x);
		else
			return meio;
	}
}