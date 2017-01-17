void tabCruz(int **tab, int m, int n){

	int a = 0;
	int b = 0;
	if (!(m % 2))
		a = 1;
	if (!(n % 2))
		b = 1;

	int acol = n / 2;
	int alin = m / 2;

	int acol2 = n % acol;
	int alin2 = m % alin;

	int i, j;
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			if ((i < alin - alin2 - a|| i > alin + alin2) && 
				(j < acol - acol2 - b|| j > acol + acol2)){
				tab[i][j] = 0;
			}
			else
				tab [i][j] = 1;
		}
	}
}
