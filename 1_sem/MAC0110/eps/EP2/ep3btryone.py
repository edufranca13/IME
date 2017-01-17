import matplotlib
matplotlib.use('TKAgg')
import matplotlib.pyplot as plt
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
	trechos = [(45*i, 45*(i+1)) for i in range(8)]
	colot = ['b']
	print trechos
	H = list()
	angles = list()

	for i in range(len(listaCordas)):
		angles.append(listaCordas[i][0][1])
		angles.append(listaCordas[i][1][1])

	angles.sort()
	print angles

	l = 0
	for j in range(8):
		c = 0
		for i in range(l, len(angles)):
			if angles[i] < trechos[j][1]:
				c += 1
				l += 1
		H.append(c)
	print H

	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	thetas = np.arange(0, 2*np.pi, 0.01)
	ax0.plot(R*np.cos(thetas), R*np.sin(thetas), '-b')

	for a in angles:
		ax0.plot([R*np.cos(a)], [R*np.sin(a)], '-bo')
	plt.show()

# def distribuicaoRadial(listaCordas):



lista = [((20,270), (20, 60)), ((20,45), (20, 90)), ((20,60), (20, 85)), ((20,65), (20, 70))]

distribuicaoBorda(lista)
