tresReversao:	tresReversao.o	tuple.o	binarySearchfo.o	mergesort.o
	gcc tresReversao.o tuple.o binarySearchfo.o mergesort.o -o TresReversao -Wall -pedantic -ansi -O2

tresReversao.o:	tresReversao.c	tuple.h	binarySearchfo.h	mergesort.h
	gcc -c tresReversao.c

tuple.o:	tuple.c	tuple.h
	gcc -c tuple.c

binarySearchfo.o:	binarySearchfo.c	binarySearchfo.h
	gcc -c binarySearchfo.c

mergesort.o:	mergesort.c	mergesort.h
	gcc -c mergesort.c