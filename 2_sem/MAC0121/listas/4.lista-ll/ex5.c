#include <stdio.h>
#include <stdlib.h>

typedef struct reg {

	int data;
	struct reg* prox;

} celula;


celula* insereNoFim(celula* inicio, int data){

	celula* p = inicio;
	celula* ant = NULL;
	while (p != NULL){
		ant = p;
		p = p->prox;
	}

	celula* novo = malloc(sizeof(celula));
	novo->data = data;

	if (ant == NULL){
		novo->prox = inicio;
		inicio = novo;
	}
	else {
		ant->prox = novo;
		novo->prox = p;		
	}


	return inicio;
}

void imprimeLista(celula* p){

	while (p != NULL){
		printf("%d ", p->data);
		p = p->prox;
	}
	printf("\n");
}

celula* inverteLista(celula* original){

	celula* prox;
	celula* atual = original;
	celula* ant = NULL;
	while (atual != NULL){
		prox = atual->prox;
		atual->prox = ant;
		ant = atual;
		atual = prox;
	}
	return ant;
}

int main(int argc, char const *argv[])
{
	celula* inicio = NULL;

	inicio = insereNoFim(inicio, 5);
	inicio = insereNoFim(inicio, 10);
	inicio = insereNoFim(inicio, 16);
	inicio = insereNoFim(inicio, 20);

	imprimeLista(inicio);

	celula* inversa = inverteLista(inicio);

	imprimeLista(inversa);

	
	return 0;
}
