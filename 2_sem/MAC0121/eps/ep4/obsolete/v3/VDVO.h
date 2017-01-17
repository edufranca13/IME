typedef struct {

	data* data;
	int max;
	int ultimo;

} vetor;

void imprimeV(vetor *p);

vetor *criaV(int n);

int buscaBinaria(vetor *p, char *c, int inicio, int fim);

void rearranjaV(vetor *p, int indice);