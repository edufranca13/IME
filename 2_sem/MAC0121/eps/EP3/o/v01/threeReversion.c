#include <stdlib.h>
#include "quicksort.h"
#include "binarySearch.h"

void threeReversionSort(float v[], int n){

	float *w;
	w = malloc(sizeof(float)*(n+1));
	
	int i;
	for (i = 0; i < n; i++)
		w[i] = v[i];

	quicksort(w, 0, n-1);

	int right_index;

	for (i = 0; i < n; i++){

		right_index = binarySearch(w, 0, n, v[i]);
		int j = i;
		

	}

}


int main(int argc, char const *argv[])
{

	float v[] = {1,5,6,9,3,2};
	threeReversionSort(v, 6);

	return 0;
}