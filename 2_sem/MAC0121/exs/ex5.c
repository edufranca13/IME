#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaChar.h"

void inverteTexto(char s[]){

        int i;
        pilha *p;
        char c;

        p = criaPilha(strlen(s));

        for (i = 0; s[i] != '\0'; i++){
                if (s[i] != ' '){
                        empilha(p, s[i]);
                }
                else{
                        while (!pilhaVazia(*p))
                                printf("%c", desempilha(p));
                        printf(" ");
                }
        }

        while (!pilhaVazia(*p))
                printf("%c", desempilha(p));
}

int main() {

        inverteTexto("Hello World MotherFucker");

        return 0;
}