import numpy as np
import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches
from math import sin, cos, radians

def leEntrada(nome):
	estado = list()
	openFile = open(nome)
	for line in openFile:
		sLine = line.strip()
		if len(sLine)==1:
			if sLine == 'Q':
				tipo = 0
			elif sLine == 'H':
				tipo = 1
		else:
			x,y = sLine.split(',')
			estado.append((int(x), int(y)))
	return estado

def contaVizinhosQuad(i,j, m, n, estado):
	count = 0
	for l in range(-1,2):
		for k in range(-1,2):
			if l == 0  and k == 0:
				continue
			else:
				if l + i > m:
					x = l + i - m
				elif l + i < 0:
					x = l + i + m
				else:
					x = l + i
				if k + j > n:
					y = k + j - n
				elif k + j < 0:
					y = k + j + n
				else:
					y = k + j
			if (x,y) in estado:
				count += 1
	return count

def contaVizinhosHexa(i,j,m,n,estado):
	count = 0
	for l in range(-1,2):
		for k in range(-1,2):
			if l == 0  and k == 0 or \
			(i%2 == 0 and (l== 1 and k == 1 or l == -1 and k==1)) or\
			(i%2 != 0 and (l== -1 and k== -1 or l==1 and k == -1)):
				continue
			else:
				if l + i > m:
					x = l + i - m
				elif l + i < 0:
					x = l + i + m
				else:
					x = l + i
				if k + j > n:
					y = k + j - n
				elif k + j < 0:
					y = k + j + n
				else:
					y = k + j
			if (x,y) in estado:
				count += 1
	return count


def simulaQuad(m,n,estado,numeroIteracoes):

	for z in range(numeroIteracoes):
		novoEstado = list()
		desenhaQuad(m,n,estado,'figura')
		for i in range(m):
			for j in range(n):
				nVizinhos = contaVizinhosQuad(i,j,m,n,estado)
				if nVizinhos == 3:
					novoEstado.append((i,j))
				elif nVizinhos == 2 and (i,j) in estado:
					novoEstado.append((i,j))
		estado = novoEstado
	return novoEstado

def simulaHexa(m,n,estado,numeroIteracoes):
	for z in range(numeroIteracoes):
		novoEstado = list()
		desenhaHexa(m,n,estado,'figuras')
		for i in range(m):
			for j in range(n):
				nVizinhos = contaVizinhosHexa(i,j,m,n,estado)
				if (nVizinhos == 3 or nVizinhos == 5) and \
					(i,j) not in estado:
					novoEstado.append((i,j))
				elif nVizinhos == 2 and (i,j) in estado:
					novoEstado.append((i,j))
		estado = novoEstado
	return novoEstado

def desenhaQuad(m,n,estado, figura):
	grid = list()
	position = list()
	for j in range(n):
		for i in range(m):
			verts = [
				(0.+i, 0.+j),
				(0.+i, 1.+j),
				(1.+i, 1.+j),
				(1.+i, 0.+j),
				(0.+i, 0.+j),
				]

			codes = [Path.MOVETO,
		 		Path.LINETO,
		 		Path.LINETO,
		 		Path.LINETO,
		 		Path.CLOSEPOLY,
		 		]

			path = Path(verts, codes)

			grid.append(path)
			position.append((i,j))

	fig = plt.figure()
	ax = fig.add_subplot(111)
	ax.set_xlim(-5,m+5)
	ax.set_ylim(-5,n+5)

	for path, pos in zip(grid, position):

		if pos in estado:
			color = 'blue'
		else:
			color = 'red'

		patch = patches.PathPatch(path, facecolor=color, lw=1, edgecolor='black')
		ax.add_patch(patch)

	plt.show()
	#plt.savefig(figura)

def desenhaHexa(m,n,estado, figura):
	grid = list()
	position = list()

	a = sin(radians(30))
	b = cos(radians(30))

	for j in range(n):
		for i in range(m):      
			
			if i % 2 == 0:
				desloc = 0
			else:
				desloc = cos(radians(30))

			verts = [
				(0.0+i*(1+a), 0.0+j*2*b+desloc),
				(1.0+i*(1+a), 0.0+j*2*b+desloc),
				(1.0+a+i*(1+a), b+j*2*b+desloc),
				(1.0+i*(1+a), 2.0*b+j*2*b+desloc),
				(0.0+i*(1+a), 2.0*b+j*2*b+desloc),
				(-a+i*(1+a), b+j*2*b+desloc),
				(0.0+i*(1+a), 0.0+j*2*b+desloc),
			]

			codes = [Path.MOVETO,
			 		Path.LINETO,
			 		Path.LINETO,
			 		Path.LINETO,
			 		Path.LINETO,
			 		Path.LINETO,
			 		Path.CLOSEPOLY,
			 ]

			path = Path(verts, codes)

			grid.append(path)
			position.append((i,j))

	fig = plt.figure()
	ax = fig.add_subplot(111)
	ax.set_xlim(-5,m*(1+a)+5)
	ax.set_ylim(-5,n*(2*b)+5)

	for path, pos in zip(grid, position):

		if pos in estado:
			color = 'blue'
		else:
			color = 'red'

		patch = patches.PathPatch(path, facecolor=color, edgecolor='black', lw=2)
		ax.add_patch(patch)

	plt.show()
	#plt.savefig(figura)

# estado = leEntrada('20x20_row.txt')
# simulaQuad(20,20,estado,5)

estado = leEntrada('file.txt')
simulaQuad(5,5,estado,4)



