#include <stdio.h>
#include <stdlib.h>

int numDig(int n){

	if (n < 10)
		return 1;
	else 
		return 1 + numDig(n/10);
}

int main(){

	printf("%d\n", numDig(123));

	return 0;
}
