#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "pilha.c"
#include "matrizes.c"
#include "matrizes.h"

int prec(char c){

	switch(c) {

		case '(':
			return 4;
		case '*':
			return 3;
		case '/':
			return 3;
		case '+':
			return 2;
		case '-':
			return 2;
		case ')':
			return 1;
	}
	return 0;
}


void posFixa(char s[]){

	pilha *p; 
	int i;
	char cTopo;

	p = criaPilha(strlen(s));

	for (i = 0; s[i] != '\0'; i++){
		if (s[i] >= 'A' && s[i] <= 'Z'){
			printf("%c", s[i]);
		}
		else {
			if (s[i] == '('){
				empilha(p, s[i]);
			}
			else {
				if (pilhaVazia(*p)){
					empilha(p, s[i]);
				}
				if (s[i] == ')'){
					while((cTopo = desempilha(p)) != '('){
						printf("%c", cTopo);
					}
				}
				else {
					cTopo = topoPilha(*p);
					while (!pilhaVazia(*p) && prec(cTopo) >= prec(s[i])){
						printf("%c", desempilha(p));
						if (!pilhaVazia(*p)){
							cTopo = topoPilha(*p);
						}
					}
					empilha(p, s[i]);
				}
			}
			while (!pilhaVazia(*p)){
				printf("%c", desempilha(p));
			}

			destroiPilha(p);
		}
	}
}

int main() {

	return 0;

}