#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){

	printf("*");
	if ((n == 1) || (n == 2))
		return (1);
	return (fibonacci(n-1) + fibonacci(n-2));
}

int fibo(int n){

	if ((n == 1) || (n == 2))
		return (1);
	return (fibo(n-1) + fibo(n-2));
}

int main(int argc, char* const argv[]){
	
	int e = fibonacci(4);
	printf("stars of 4: %d\n", 1+ fibo(4) + fibo(2));
	int f = fibonacci(5);
	printf("stars of 5: %d\n", 1+ fibo(5) + fibo(3)); 
	int g = fibonacci(6);
	printf("stars of 6: %d\n", 1+ fibo(6) + fibo(4));
	int h = fibonacci(7);
	printf("stars of 7: %d\n", 1+ fibo(7) + fibo(5));
	int l = fibonacci(8);
	printf("stars of 8: %d\n", 1+ fibo(8) + fibo(6));

	return 0;
}
