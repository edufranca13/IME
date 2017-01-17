


int nRainhasR(int n, int **tab, int atual){

	int col;
	if (n == atual)
		return 1;

	for (col = 0; col < n; col++)
		if (podeColocar(tab, n, atual, col)){
			tab[atual][col] = 1;
			if (nRainhasR(n, tab, atual+1))
				return 1;
			tab[atual][col] = 0;
		}
	return 0;
}