#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "VDVO.h"
#include "tabelaSimbolo_VO.h"

vetor *insereOrdenadoV(vetor *p, char *c){
	
	int indice;
	char *c2;
	
	c2 = malloc(1024);
	strcpy(c2, c);

	indice = buscaBinaria(p, c2, 0, p->ultimo - 1);

	if (p->ultimo == indice || strcmp(p->data[indice].palavra, c2) != 0){
		rearranjaV(p, indice);
		p->data[indice].palavra = c2;
		p->data[indice].contador = 1;
		p->ultimo++;
	}
	else {
		p->data[indice].contador++;
	}
	return p;
}