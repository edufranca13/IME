#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "VDVO.h"
#include "tabelaSimbolo_VD.h"

vetor *insereDesordenadoV(vetor *p, char *c){

	int i;
	char *c2;
	
	c2 = malloc(1024);
	strcpy(c2, c);

	for (i = 0; i < p->ultimo; i++){
		if (strcmp(p->data[i].palavra, c2) == 0){
			p->data[i].contador++;
			return p;
		}
	}

	if (p->ultimo == p->max - 1)
		rearranjaV(p, i);
	p->data[i].palavra = c2;
	p->data[i].contador = 1;
	p->ultimo++;

	return p;
}