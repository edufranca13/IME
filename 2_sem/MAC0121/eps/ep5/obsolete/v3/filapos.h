typedef struct pos {

	int x;
	int y;

} pos;

typedef struct {

	pos *v;
	int max;
	int fim;
	int inicio;

} fila;

fila *criaFila(int max);
int filaVazia(fila f);
int filaCheia(fila f);
void realocaFila(fila *f);
pos removeFila(fila *f);
void insereFila(fila *f, pos x);
