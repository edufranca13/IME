#include <stdio.h>
#include <stdlib.H>

//n e o numero de pedidos
//k e o numero de barras
//atual e o numero do pedido atual (indice do vetor)
int decideProducao(int n, float pedidos[], int k, float tambarras[], int atual) {

	int barra;

	if (atual == n)
		return 1;

	for (barra = 0; barra < k; barra++){

		if(tambarras[barra] >= pedidos[atual]){
			tambarras[barra] -= pedidos[atual];
			if(decideProducao(n, pedidos, k, tambarras, atual+1))
				return 1;
			tambarras[barra] += pedidos[atual];
		}
	}
	return 0;
}


int main() {

	int n = 3;
	int k = 2;

	float pedidos[3] = {3.0, 3.0, 3.0};

	float *tambarras;
	tambarras = malloc(k*sizeof(float));

	int i;
	for (i = 0; i < k; i++)
		tambarras[i] = 6;

	int x;
	x = decideProducao(n, pedidos, k, tambarras, 0);

	printf("%d\n",x);
}