#include <stdio.h>

int main(){
	double x = 1.0/3.0; 
	double y = 1.0/5.0;

	double *pd;

	printf("%f %f\n", x, y);

	pd = &x;

	printf("%f\n%p\n%p\n", *pd, pd, &pd);

	return 0;
}