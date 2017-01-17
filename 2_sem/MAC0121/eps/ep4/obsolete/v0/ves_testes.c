#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {

	char* palavra;
	int contador;
} celula;

typedef struct {

	celula* data;
	int max;
	int ultimo;

} vetor;

void imprimeVetor(vetor *p){

	int i;
	for (i = 0; i < p->ultimo; i++)
		printf("%s : %d\n", p->data[i].palavra, p->data[i].contador);
}

vetor *criaVetor(int n){

	vetor *p = malloc(sizeof(vetor));
	p->data = malloc(sizeof(celula)*n);
	p->max = n;
	p->ultimo = 0;

	return p;
}

void merge(vetor *p, int inicio, int meio, int fim){

	vetor *w = criaVetor(p->max);

	int i = inicio;
	int j = meio;
	int k = 0;

	while (i < meio && j < fim) {
		if (p->data[i].contador <= p->data[j].contador)
			w->data[k++] = p->data[i++];
		else
			w->data[k++] = p->data[j++];
	}

	while (i < meio) w->data[k++] = p->data[i++];
	while (j < fim) w->data[k++] = p->data[j++];

	for (i = inicio; i < fim; i++) 
		p->data[i] = w->data[i-inicio];

	free(w);
}

void mergeSort(vetor *p, int inicio, int fim){

	if (inicio < fim - 1){
		int meio = (inicio + fim)/2;
		mergeSort(p, inicio, meio);
		mergeSort(p, meio, fim);
		merge(p, inicio, meio, fim);
	}
}

int buscaBinaria(vetor *p, char *c, int inicio, int fim){

	if (inicio > fim)
		return inicio;
	
	int meio = (inicio + fim)/2;	

	if (strcmp(p->data[meio].palavra, c) == 0)
		return meio;
	else if (strcmp(p->data[meio].palavra, c) > 0)
		return buscaBinaria(p, c, inicio, meio - 1);
	else
		return buscaBinaria(p, c, meio + 1, fim);
	
}

void rearranjaVetor(vetor *p, int indice){

	vetor *w;

	if (p->ultimo == p->max - 1)
		w = criaVetor(p->max*2);
	else
		w = criaVetor(p->max);

	w->ultimo = p->ultimo;

	int i;
	for (i = 0; i < indice; i++)
		w->data[i] = p->data[i];

	for (i = indice + 1; i <= p->ultimo; i++)
		w->data[i] = p->data[i-1];

	free(p->data);
	p->data = w->data;
	p->max = w->max;
}

vetor *insereOdernadoVec(vetor *p, char *c){

	char* c2;
	c2 = malloc(1024);
	strcpy(c2, c);

	int indice = buscaBinaria(p, c2, 0, p->ultimo - 1);

	if (p->ultimo == indice || strcmp(p->data[indice].palavra, c2) != 0){
		rearranjaVetor(p, indice);
		p->data[indice].palavra = c2;
		p->data[indice].contador = 1;
		p->ultimo++;
	}
	else {
		p->data[indice].contador++;
	}

	return p;
}

vetor *insereDesordenadoVec(vetor *p, char *c){

	char* c2;
	c2 = malloc(1024);
	strcpy(c2, c);

	int i;
	for (i = 0; i < p->ultimo; i++){
		if (strcmp(p->data[i].palavra, c2) == 0){
			p->data[i].contador++;
			return p;
		}
	}
	
	rearranjaVetor(p, i);
	p->data[i].palavra = c2;
	p->data[i].contador = 1;
	p->ultimo++;

	return p;
}



int main(int argc, char const *argv[])
{
	vetor *p = criaVetor(10);

	p = insereDesordenadoVec(p, "isso");
	p = insereDesordenadoVec(p, "e");
	insereDesordenadoVec(p, "um");
	insereDesordenadoVec(p, "teste");
	insereDesordenadoVec(p, "teste");

	mergeSort(p, 0, p->ultimo);

	imprimeVetor(p);

	// p->data[0].palavra = "a";
	// p->data[1].palavra = "b";
	// p->data[2].palavra = "d";
	// p->data[3].palavra = "e";
	// p->data[4].palavra = "f";

	// int indice = buscaBinaria(p, "d", 0, 1);

	// printf("%d\n", indice);

	return 0;
}