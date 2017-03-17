#include "pilha.c"

pilha *criaPilha(int max);

int pilhaVazia(pilha p);

void realocaPilha(pilha *p);

void empilha(pilha *p, int x);

int desempilha(pilha *p);