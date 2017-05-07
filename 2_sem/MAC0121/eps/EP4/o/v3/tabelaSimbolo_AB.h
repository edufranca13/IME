typedef struct noA {

	data data;
	struct noA *esq;
	struct noA *dir;
} ramo;

typedef ramo *apontadorA;

void imprimeEmOrdem(apontadorA raiz);

apontadorA novaCelula(char *c);

apontadorA insereAB(apontadorA raiz, char *c);

void armazenaArvore(apontadorA raiz, data arr[], int *index_ptr);

void arrAB (data *arr, apontadorA raiz, int *index_ptr);

int contaNos(apontadorA raiz);

void sortAB(apontadorA raiz);