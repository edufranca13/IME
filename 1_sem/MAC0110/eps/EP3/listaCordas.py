import config
from random import random
from math import sqrt, degrees, acos

#metodos que geram cordas listaCordasM1, listaCordasM2, listaCordasM3
#le o raio e o numero de cordas desejado e retorna uma lista de tuplas 
#representando os pares de pontos dos extremos das cordas

# cria lista de tuplas representando pares de pontos da corda gerados aleatoriamente na borda da circuferencia
def listaCordasM1(r, n):
	return [(points_on_circle(r), points_on_circle(r)) for i in range(n)]

# cria pontos medios de cordas gerados aleatoriamente ao longo de um raio em qualquer direcao
# gera lista de tuplas representando pares de pontos da corda gerados atraves da funcao determinaPontosExtremos
def listaCordasM2(r,n):
	pontos_medios = [(r*random(), 360*random()) for i in range(n)]
	return determinaPontosExtremos(pontos_medios)

#cria pontos medios de cordas gerados aleatoriamente em qualquer local da circuferencia
# gera lista de tuplas representando pares de pontos da corda gerados atraves da funcao determinaPontosExtremos
def listaCordasM3(r,n):
	pontos_medios = [(points_in_circle(r)) for i in range(n)]
	return determinaPontosExtremos(pontos_medios)

#gera aleatoriamente  um ponto na borda da circuferencia em coordenadas polares
def points_on_circle(r):
	return (r, 360*random())

#gera aleatoriamente um ponto dentro do circulo em coordenadas polares
def points_in_circle(r):
	return (sqrt(random())*r, 360*random())

#recebe uma lista de pontos medios de cordas
#retorna uma lista com os pontos extremos das cordas
def determinaPontosExtremos(listaMedios):
	ponto_extremos = list()
	for i in range(len(listaMedios)):
		a1 = listaMedios[i][1] - degrees(acos(float(listaMedios[i][0])/config.R))
		if a1 > 360:
			while a1 > 360:
				a1 -= 360
		if a1 < 0:
			while a1 < 0:
				a1 += 360
		a2 = listaMedios[i][1] + degrees(acos(float(listaMedios[i][0])/config.R))
		if a2 > 360:
			while a2 > 360:
				a2 -= 360
		if a2 < 0:
			while a2 < 360:
				a2 += 360
		r1,r2 = float(config.R), float(config.R)
		ponto_extremos.append(((r1,a1), (r2, a2)))
	return ponto_extremos