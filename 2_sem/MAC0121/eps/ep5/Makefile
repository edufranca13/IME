hex:	hex.o	tabuleiro.o	filapos.o	caminho.o	
	gcc hex.o tabuleiro.o filapos.o caminho.o -o ep5 -Wall -pedantic -ansi -g -O2

hex.o:	hex.c	filapos.h
	gcc -c hex.c

tabuleiro.o:	tabuleiro.c
	gcc -c tabuleiro.c

filapos.o:	filapos.c
	gcc -c filapos.c

caminho.o:	caminho.c	tabuleiro.h	filapos.h
	gcc -c caminho.c

