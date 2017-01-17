int **criaMatriz(int m, int n){

	int **matriz, i;

	matriz = malloc(m*sizeof(int*));

	for (i = 0; i < m; i++)
		matriz[i] = malloc(n*sizeof(int));

	return matriz;
}

void imprimeMatriz(int **matriz, int m, int n){

	int i, j;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++)
			printf("%d\t", matriz[i][j]);
		printf("\n");
	}
}

void liberaMatriz(int **matriz, int m, int n){

	int i;
	for (i = 0; i < m; i++)
		free(matriz[i]);

	free(matriz);
}