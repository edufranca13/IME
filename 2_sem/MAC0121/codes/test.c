#include <stdio.h>
#include <stdlib.h>


int livre(int (*M)[4], int x, int y){
	return M[x][y];
}

void muda(int (*M)[4], int x, int y){
	M[x][y] = 1;
}

void imprime(int (*M)[4]) {
	int i;
	int j;
	for (i = 0; i < 4; i++)
		printf("\n");
		for (j = 0; j < 4; j++)
			printf("%d\n", M[i][j]);
}
int main() {


	int M[4][4];

	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			M[i][j] = 0;

	int x = 0;
	int y = 0;
	while(x != -1 && x != 4){
		if (!livre(M, x, y)){
			muda(M, x, y);
			x++;
			y = 0;
		}
		else {
			y++;
		}
	}

	return 0;
}