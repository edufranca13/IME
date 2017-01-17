restaUm:	restaUm.o	matriz.o	auxResta.o	pilha.o
	gcc restaUm.o matriz.o auxResta.o pilha.o -o restaUm -Wall -pedantic -ansi -O2

restaUm.o:	restaUm.c	matriz.h	auxResta.h	pilha.h
	gcc -c restaUm.c

matriz.o:	matriz.c	matriz.h
	gcc -c matriz.c

auxResta.o:	auxResta.c	auxResta.h	matriz.h
	gcc -c auxResta.c

pilha.o:	pilha.c	pilha.h
	gcc -c pilha.c