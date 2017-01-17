#include "auxResta.c"

int contaUmTab(int **tab, int m, int n);

int contaMenosUmTab(int **tab, int m, int n);

int ePeca(int **tab, int l, int c);

int podeComer(int **tab, int l, int c, int mov, int m, int n);

void come(int **tab, int l, int c, int mov);

void volta (int **tab, int l, int c, int mov);

pos penultimo(pos atual, int m, int n);

int **inverteTab(int **tab, int m, int n);

int contaUns(int **tab, int m, int n, int a);