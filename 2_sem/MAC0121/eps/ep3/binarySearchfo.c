#include "tuple.h"
#include "binarysearchfo.h"

int binarysearchfo(tuple v[], int inicio, int fim, int x){

	if (inicio > fim)
		return -1;
	else {

	int meio = (inicio + fim)/2;

	if (x == v[meio].value){
		if (x == v[--meio].value && meio >= -1)
			return binarysearchfo(v, inicio, meio + 1, x);
		else
			return meio+1;
	}
	else if (x > v[meio].value)
		return binarysearchfo(v, meio + 1, fim, x);
	else
		return binarysearchfo(v, inicio, meio - 1, x);

	}
}