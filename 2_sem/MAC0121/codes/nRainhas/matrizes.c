int **criaMatriz(int m, int n){

	int **mat, i;

	mat = malloc(m*sizeof(int*));

	for (i = 0; i < m; i++)
		mat[i] = malloc(n*sizeof(int));

	return mat;
}

void imprimeMatriz(int **mat, int m, int n){

	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}

void destroiMatriz(int **mat, int m){

	int i;
	for (i = 0; i < m; i++)
		free(mat[i]);

	free(mat);
}

void iniciaMatriz(int **tab, int m, int n){

	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			tab[i][j] = 0;
}