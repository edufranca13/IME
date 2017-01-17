typedef struct {

	pos *v;
	int topo;
	int max;

} pilha;

pilha* criaPilha(int maximo);

void realocaPilha(pilha *p);

int pilhaVazia(pilha p);

void empilha(pilha *p, pos x);

pos desempilha(pilha *p);

void destroiPilha(pilha *p);

void imprimePilha(pilha *p);