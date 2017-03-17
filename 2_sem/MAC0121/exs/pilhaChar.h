#include "pilhaChar.c"

pilha *criaPilha(int max);

int pilhaVazia(pilha p);

void realocaPilha(pilha *p);

void empilha(pilha *p, char x);

char desempilha(pilha *p);