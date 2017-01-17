import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
import numpy as np
from math import cos
from ep3trya import histograma

global R

R  = 20

def determinaPontosMedios(listaExtremos):
	pontos_medios = list()
	for i in range(len(listaExtremos)):
		m, n = (listaExtremos[i][0][0]*cos(listaExtremos[i][0][1])+
					listaExtremos[i][1][0]*cos(listaExtremos[i][1][1]))/2, \
						(listaExtremos[i][0][1]+listaExtremos[i][1][1])/2
		pontos_medios.append((m,n))
	return pontos_medios

# def determinaPontosExtremos(listaPontosMedios):

def distribuicaoBorda(listaCordas):

	angles = list()

	for i in range(len(listaCordas)):
		angles.append(listaCordas[i][0][1])
		angles.append(listaCordas[i][1][1])


	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	thetas = np.arange(0, 2*np.pi, 0.01)
	ax0.plot(R*np.cos(thetas), R*np.sin(thetas), '-b')

	for a in angles:
		ax0.plot([R*np.cos(a)], [R*np.sin(a)], '-bo')

	ax0.grid()
	H = ax1.hist(angles, 8, range = [0, 360])
	print H
	ax1.grid()
	plt.show()

def distribuicaoRadial(listaCordas):

	radius = list()

	for i in range(len(listaCordas)):
		radius.append(listaCordas[i][0][0])
		radius.append(listaCordas[i][1][0])


	radius.sort()

	d = {}
	l = 0
	for j in range(1,8):
		for r in radius:
			if r <= j*R/8:
				if j in d:
					d[j] += 1
				else:
					d[j] = 1

	print d


	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	
	thetas = np.arange(0, 2*np.pi, 0.01)
	ax0.plot(R*np.cos(thetas), R*np.sin(thetas), '-b')

	for i in range(len(listaCordas)):
		ax0.plot([listaCordas[i][0][0]*np.cos(listaCordas[i][0][1])], \
			[listaCordas[i][0][0]*np.sin(listaCordas[i][0][1])], 'yo')

	ax0.grid()
	H = ax1.hist(radius, 8, range = [0, R])
	print H
	ax1.grid()
	plt.show()

lista = [((10,0), (20, 45)), ((15,45), (20, 135)), ((5,135), (20, 135)), ((20,135), (20, 135))]

distribuicaoRadial(lista)
