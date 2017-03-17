#include "quicksort.h"
#include "binarySearch.h"

int main(int argc, char const *argv[])
{
	
	float v[] = {6,2,4,6,7,9,3};

	quicksort(v, 0, 6);

	int i;
	for (i = 0; i < 7; ++i)
	{
		printf("%.f ", v[i]);
	}

	printf("\n");

	int a = binarySearch(v, 0, 6, 4);

	printf("%d\n", a);

	return 0;
}