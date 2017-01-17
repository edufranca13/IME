#include <stdio.h>
#include <stdlib.h>

int euclides(m, n){

	if (n == 0)
		return m;
	else
		return euclides(n, m % n);
}

int main(int argc, char* const argv[]){

	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

	printf("%d", euclides(m, n));

	return 0;
}
