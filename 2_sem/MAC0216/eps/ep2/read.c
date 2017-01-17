#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ss.h"

char* makeWord(char *c, int j, int i){

	char *s;
	s = malloc(sizeof(char)*i-j);
	int k;
	for (k = 0; k < i - j; k++){
		s[k] = c[j+k];
	}

	return s;
}

void read(char c[]){

	int word = 0;
	int ok;
	int i = 0;
	int j;

	SymbolTable* st;
	st = NULL;

	while(c[i] != '\0'){

		while (isspace(c[i]) && c[i] != '\0'){
			i++;
		}
		
		ok = 0;
		j = i;
		
		while(!isspace(c[i]) && c[i] != '\0'){
			i++;
			ok = 1;
		}


		if(ok){
			word++;
			//printf("j:%d i:%d\n", j, i);
			st = stable_insert(st,makeWord(c, j, i));
		}
	}

	printInOrder(st);

}

int main(){

	read("hello darkness my old friend hello hello hello hello");

	// SymbolTable* st;
	// st = NULL;

	// st = stable_insert(st, "hi");
	// st = stable_insert(st, "hello");
	// st = stable_insert(st, "hol");
	// st = stable_insert(st, "ola");
	// st = stable_insert(st, "ciao");
	// st = stable_insert(st, "zid");

	// printInOrder(st);

	return 0;
}