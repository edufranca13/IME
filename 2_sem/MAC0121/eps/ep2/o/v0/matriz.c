int **criaMatriz(int m, int n){

	int **matriz = malloc(m*sizeof(int*));
	int i;
	for (i = 0; i < m; i++){
		matriz[i] = malloc(n*sizeof(int));
	}

	return matriz;
}

void imprimeMatriz(int **matriz, int m, int n){

	int i, j;

	for(i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d\t", matriz[i][j]);
		printf("\n");
	}
	printf("\n");
}

void iniciaMatriz(int **matriz, int m, int n){
	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			matriz[i][j] = 1;
}

void destroiMatriz(int **matriz, int m){

	int i;
	for (i = 0; i < m; i++)
		free(matriz[i]);

	free(matriz);
}

int comparaMatrizes(int **mat1, int **mat2, int m, int n){

	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (mat1[i][j] != mat2[i][j])
				return 0;
	return 1;
}