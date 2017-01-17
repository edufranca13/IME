#define N 100

static int pilha[N];
static int topo;

void criaPilha(){
	topo = 0;
}

void empilha(int x){
	pilha[topo++] = x;
}

int desempilha(){
	return pilha[--topo];
}