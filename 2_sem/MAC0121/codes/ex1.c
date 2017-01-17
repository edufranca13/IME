#include <stdio.h>
#include <stdlib.h>

#define MAX 100;

int pilha[MAX];
int t = 0;

void empilha(char c){
	pilha[t++] = c;
}

char desempilha(){

	char c = pilha[--t];
	return c;
}

int pilhaVazia(){

	return t == 0;
}

int pilhaCheia(){
	return t == 10;
}

void inverte(char s[]){

	int i;
	for (i = 0; s[i] != '\0'; i++){
		empilha(s[i]);
	}

	int j;
	char c;
	for (j = 0; j < i; ++j)
	{
		c = desempilha();
		printf("%c", c);
	}
}

int main(){

	inverte("Hello");

	return 0;

}