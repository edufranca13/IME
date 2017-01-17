import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
import numpy as np
from auxep3 import extract, extract_m, find_key, classify_a, classify_r, classify_r2
from listaCordas import listaCordasM1, listaCordasM2, listaCordasM3
import config


#recebe duas tuplas representando coordenadas
#retorna a distancia entre as coordenadas
def dist(a, b):
	dist = 0
	for xa, xb in zip(a,b):
		dif = xa - xb
		dist += dif**2
	return np.sqrt(dist)

#recebe lista com os pontos extremos de uma corda
#retorna os pontos medios das cordas
def determinaPontosMedios(listaExtremos):
	
	pontos_medios = list()

	for i in range(len(listaExtremos)):
		if listaExtremos[i][0][1] > listaExtremos[i][1][1]:
			alfa = listaExtremos[i][1][1] + (listaExtremos[i][0][1] - listaExtremos[i][1][1])/2
			r = np.cos(np.radians(alfa - listaExtremos[i][1][1]))*config.R
		else:
			alfa = listaExtremos[i][0][1] + (listaExtremos[i][1][1] - listaExtremos[i][0][1])/2
			r = np.cos(np.radians(alfa - listaExtremos[i][0][1]))*config.R

		pontos_medios.append((r, alfa))

	return pontos_medios


def distribuicaoBorda(listaCordas):

	#extrai apenas os angulos da lista de cordas
	angles = extract(listaCordas, 1)

	#classifica cada angulo de acordo com sua posicao na circuferencia
	d = classify_a(angles)

	#gera o grafico da circuferencia usando matplotlib
	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	ax0.plot(config.R*np.cos(np.arange(0, 2*np.pi, 0.01)), config.R*np.sin(np.arange(0, 2*np.pi, 0.01)), '-b')

	#plota os extremos das cordas colorindo-os de acordo com a classificacao
	for a in angles:
		ax0.plot([config.R*np.cos(np.pi*a/180)], [config.R*np.sin(np.pi*a/180)], color=find_key(d, a), marker='o')
	ax0.grid()

	#gera o histograma desses pontos. so ha oito divisoes (45 graus) de 0 a 360 graus. 
	ax1.hist(angles, 8, range = [0, 360])
	ax1.grid()

	plt.show()
	#plt.savefig('distribuicao_borda.png')

def distribuicaoRadial(listaCordas):

	#extrai os pontos medio da lista de cordas
	pontos_medios = determinaPontosMedios(listaCordas)
	#extrai separadamente para o manuseio o angulo e o raio de cada ponto medios
	angles = extract_m(pontos_medios, 1)
	radius = extract_m(pontos_medios, 0)
	print(radius)

	#classifica cada raio de acordo com sua posicao no circulo - vide classify_r
	d = classify_r(radius)

	#gera o grafico do circulo usando matplotlib
	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	ax0.plot(config.R*np.cos(np.arange(0, 2*np.pi, 0.01)), config.R*np.sin(np.arange(0, 2*np.pi, 0.01)), '-b')

	#plota os pontos medios encontrados
	for r, a in zip(radius, angles):
		ax0.plot([r*np.cos(np.pi*a/180)], [r*np.sin(np.pi*a/180)], color=find_key(d, np.fabs(r)), marker='o')
	ax0.grid()
	
	# #converte os raios dos pontos médios em positivos
	rp = [np.fabs(radius[i]) for i in range(len(radius))]
	
	#gera o histograma desses pontos. so ha oito divisoes (8 coroas) de 0 ate o raio do circulo.
	ax1.hist(rp, 8, range = [0, config.R])
	ax1.grid()

	plt.show()
	#plt.savefig('distribuicao_radial.png')

def distribuicaoArea(listaCordas):

	#extrai pontos medios da corda da lista de cordas
	pontos_medios = determinaPontosMedios(listaCordas)

	#extrai separadamente para manuseio os angulos e os raios dos pontos medios
	angles = extract_m(pontos_medios, 1)
	radius = extract_m(pontos_medios, 0)

	#classifica cada angulo de com acordo com sua posicao no circulo - vide classify_r2
	d = classify_r2(radius)

	#gera o grafico do circulo usando matplotlib
	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	ax0.plot(config.R*np.cos(np.arange(0, 2*np.pi, 0.01)), config.R*np.sin(np.arange(0, 2*np.pi, 0.01)), '-b')

	#plot os pontos medios encontrados
	for r, a in zip(radius, angles):
		ax0.plot([r*np.cos(np.pi*a/180)], [r*np.sin(np.pi*a/180)], color=find_key(d, np.fabs(r)), marker='o')
	ax0.grid()

	rp = [np.fabs(radius[i]) for i in range(len(radius))]
	#gera o histograma desses pontos. so ha oito divisoes (8 coroas de mesma area) de 0 ate o raio do circulo.
	ax1.hist(rp, [config.R*np.sqrt((j+1)/8) for j in range(8)], range = [0, config.R])

	ax1.grid()
	
	plt.show()
	#plt.savefig('distribuicao_area.png')

def distribuicaoCordas(listaCordas):

	#gera o grafico do circulo usando matplotlib
	fig, ax0 = plt.subplots(ncols=1, figsize=(8, 4))
	ax0.plot(config.R*np.cos(np.arange(0, 2*np.pi, 0.01)), config.R*np.sin(np.arange(0, 2*np.pi, 0.01)), '-b')

	#algoritmo para separar a lista de pontos extremos em duas listas contendo as coordenadas x e coordenadas y 
	#usadas pelo matplotlib
	xzes = []
	yzes = []
	c = 0
	
	for par in listaCordas:
		temp1 = []
		temp2 = []
		for ponto in par:
			temp1.append(ponto[0]*np.cos(np.pi*ponto[1]/180))
			temp2.append(ponto[0]*np.sin(np.pi*ponto[1]/180))
		xzes.append(temp1)
		yzes.append(temp2)

	#usa as coordenadas geradas anteriormente para plotar as retas
	for x, y in zip(xzes, yzes):
		ax0.plot(x, y, 'r-')

	ax0.grid()

	plt.show()
	#plt.savefig('distribuicao cordas.png')

def main():
	lista1 = listaCordasM1(config.R, config.n)
	lista2 = listaCordasM2(config.R, config.n)
	lista3 = listaCordasM3(config.R, config.n)
	

	distribuicaoBorda(lista1)
	distribuicaoRadial(lista1)
	distribuicaoArea(lista1)
	distribuicaoCordas(lista1)

	distribuicaoBorda(lista2)
	distribuicaoRadial(lista2)
	distribuicaoArea(lista2)
	distribuicaoCordas(lista2)

	distribuicaoBorda(lista3)
	distribuicaoRadial(lista3)
	distribuicaoArea(lista3)
	distribuicaoCordas(lista3)
main()




