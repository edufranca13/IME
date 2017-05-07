tabelaSimbolo:	tabelaSimbolo.o	data.o	VDVO.o	LDLO.o	tabelaSimbolo_VD.o	tabelaSimbolo_VO.o	tabelaSimbolo_LD.o	tabelaSimbolo_LO.o	tabelaSimbolo_AB.o
	gcc tabelaSimbolo.o data.o VDVO.o LDLO.o tabelaSimbolo_VD.o tabelaSimbolo_VO.o tabelaSimbolo_LD.o tabelaSimbolo_LO.o tabelaSimbolo_AB.o -o tabelaSimbolo -Wall -pedantic -ansi -O2

tabelaSimbolo.o:	tabelaSimbolo.c	data.h	VDVO.h	LDLO.h	tabelaSimbolo_VD.h	tabelaSimbolo_VO.h	tabelaSimbolo_LD.h	tabelaSimbolo_LO.h	tabelaSimbolo_AB.h
	gcc -c tabelaSimbolo.c

data.o:	data.c	data.h
	gcc -c data.c

VDVO.o:	VDVO.c	data.h	VDVO.h
	gcc -c VDVO.c

LDLO.o:	LDLO.c	data.h	LDLO.h
	gcc -c LDLO.c

tabelaSimbolo_VD.o:	tabelaSimbolo_VD.c	data.h	VDVO.h	tabelaSimbolo_VD.h
	gcc -c tabelaSimbolo_VD.c

tabelaSimbolo_VO.o:	tabelaSimbolo_VO.c	data.h	VDVO.h	tabelaSimbolo_VO.h
	gcc -c tabelaSimbolo_VO.c

tabelaSimbolo_LD.o:	tabelaSimbolo_LD.c	data.h	LDLO.h	tabelaSimbolo_LD.h
	gcc -c tabelaSimbolo_LD.c

tabelaSimbolo_LO.o:	tabelaSimbolo_LO.c	data.h	LDLO.h	tabelaSimbolo_LO.h
	gcc -c tabelaSimbolo_LO.c

tabelaSimbolo_AB.o:	tabelaSimbolo_AB.c	data.h	tabelaSimbolo_AB.h
	gcc -c tabelaSimbolo_AB.c