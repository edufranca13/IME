#include <stdio.h>

int main(){
	int n = 0;
	int *pn;

	pn = &n;

	while(n != -99999) {
		printf("Entre com um valor de n (para parar entre com -99999): \n");
		scanf("%d", &n);
		printf("n: %d *pn: %d\n", n, *pn);
	}

	return 0;
}