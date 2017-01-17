#include <stdio.h>
#include <stdlib.h>

int collatz(long n, int *cache){

	long num = n;

	int passos = 0;

	while (num != 1){

		if (num % 2 == 0)
			num /= 2;
		else
			num = 3*num + 1;

		passos++;

		if (num < n){
			passos += cache[num];
			break;
		}
	}

	cache[n] = passos;

	return passos;
}

void test_collatz(long i, long f){

	int *cache;
	cache = malloc(f*sizeof(int));

	long k;
	for (k = 1; k < i; k++)
		collatz(k, cache);

	for (; i <= f; i++) {
		int p =	collatz(i, cache);
		printf("número: %lu : passos: %i\n", i, p);
	}

	free(cache);
}

int main() {

	test_collatz(1, 10000);

	return 0;
}

