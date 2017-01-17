#comentarios no relatorio

import matplotlib
matplotlib.use('TKAgg')
import numpy as np
import matplotlib.pyplot as plt

from math import sqrt, cos, sin, pi, log

def transformacaoEscala(U, V, n, a, b):
	for i in range(n):
		V[i] = a+U[i]*(b-a+1)

def somaVetores(U1, U2, U, n):
	for i in range(n):
		U[i] = U1[i]+U2[i]

def raizVetor(U,n):
	for i in range(n):
		U[i] = sqrt(U[i])

def normalTransform(U1, U2, Z0, Z1, n):
	
	for i in range(n):
		Z0[i] = cos(2*pi*U2[i])*sqrt(-2*log(U1[i]))
		Z1[i] = sin(2*pi*U2[i])*sqrt(-2*log(U1[i]))


def histograma(U, n, H, m):
	del H[:]

	interval = float((max(U) - min(U)))/(m-1)
	print(interval)
	lint = [min(U)+s*interval for s in range(m)]
	print(lint)

	l = 0
	for j in range(m):
		c = 0
		for i in range(l, n):
			if U[i] <= lint[j]:
				c += 1
				l += 1
		H.append(c)

if __name__ == '__main__':

	n = int(input('Entre com numero inteiro positivo: '))
	a = float(input('Entre com a: '))
	b = float(input('Entre com b: '))

	U = [0]*n
	U1 = np.random.uniform(0.0, 1.0, n)
	U2 = np.random.uniform(0.0, 1.0, n)
	V = np.random.uniform(0.0, 1.0, n)

	transformacaoEscala(U1,V, n, a, b)

	somaVetores(U1, U2, U, n)

	raizVetor(U1, n)

	U1 = np.random.uniform(0.0, 1.0, n)
	U2 = np.random.uniform(0.0, 1.0, n)
	Z0 = [0]*n
	Z1 = [0]*n
	
	normalTransform(U1, U2, Z0, Z1, n)

	fig, (ax0, ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	ax0.hist(U1, n)
	ax1.hist(V, n)
	ax0.grid()
	ax1.grid()
	plt.savefig('hist_escala_translacao.png')

	fig, (ax0,ax1,ax2) = plt.subplots(ncols=3, figsize=(8, 4))
	ax0.hist(U1, n)
	ax0.grid()
	ax1.hist(U2, n)
	ax1.grid()
	ax2.hist(U, n)
	ax2.grid()
	plt.savefig('hist_soma.png')

	fig, ax0 = plt.subplots(ncols=1, figsize=(8, 4))
	ax0.hist(U1, n)
	ax0.grid()
	plt.savefig('hist_raiz.png')

	fig, (ax0,ax1) = plt.subplots(ncols=2, figsize=(8, 4))
	ax0.hist(Z0, 10, range = [min(U1), max(U1)])
	ax1.hist(Z1, 10, range=[min(Z1), max(Z1)])
	ax0.grid()
	plt.savefig('hist_normal_Z0_Z1.png')


