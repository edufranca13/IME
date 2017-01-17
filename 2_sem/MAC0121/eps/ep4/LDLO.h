typedef struct no {

	data data;
	struct no *prox;
} celula;

typedef celula* apontador;

void armazenaLista(apontador inicio, data arr[], int *index_ptr);

void arrLL(data *arr, apontador inicio, int *index_ptr);

int tamanhoLista(apontador inicio);

void sortLL(apontador inicio, char const *c);

void imprimeL(apontador p);