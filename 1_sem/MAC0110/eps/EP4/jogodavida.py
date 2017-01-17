def leEntrada(nome):
	a = open(nome)
	pares = list()

	for line in a:
		l = line.strip()
		if len(l) == 1:
			if l == 'Q':
				print('grade quadrada')
				tipo = l
				continue
			elif l =='H':
				print('grade hexagonal')
				tipo = l
				continue

		x,y = l.split(',')
		pares.append((int(x),int(y)))

	return pares

def contaVizinhosVivosQuad(i, j, pares, m, n):
	count = 0
	for k in range(-1,2):
		for l in range(-1,2):
			if k == 0 and l == 0:
				continue
			else:
				if i + k > m:
					x = i + k - m
				elif i + k < 0:
					x = i + k + m
				else:
					x = i + k
				if j + l > n:
					y = j + l - n
				elif j + l < 0:
					y = j + l + n
				else: 
					y = j + l
				if (x,y) in pares:
					count += 1

	return count

def contaVizinhosVivosHexa(i, j, pares, m, n):
	count = 0
	for k in range(-1,2):
		for l in range(-1,2):
			if k == 0 and l == 0 or (j % 2 != 0 and (k== 1 and l == -1 or k == 1 and l == 1)) or j % 2 == 0 and ((k == -1 and l == -1 or k == -1 and l == 1)):
				continue
			else:
				if i + k > m:
					x = i + k - m
				elif i + k < 0:
					x = i + k + m
				else:
					x = i + k
				if j + l > n:
					y = j + l - n
				elif j + l < 0:
					y = j + l + n
				else: 
					y = j + l
				if (x,y) in pares:
					count += 1
	return count

def simulaQuad(m, n, lista, t):
	
	pares = lista

	for interacao in range(t):
		lista = pares
		pares = list()
		for i in range(m):
			for j in range(n):
				count = contaVizinhosVivosQuad(i,j, lista, m, n)
				# print("(%d, %d) tem %d vizinhos" % (i, j, count))
				if count == 3:
					pares.append((i,j))
				elif count == 2: 
					if (i,j) in lista:
						pares.append((i,j))
				else:
					pass
	return pares

def simulaHexa(m,n,lista, t):

	pares = lista

	for interacao in range(t):
		lista = pares
		pares = list()
		for i in range(m):
			for j in range(n):
				count = contaVizinhosVivosQuad(i,j, lista, m, n)
				# print("(%d, %d) tem %d vizinhos" % (i, j, count))
				if count == 3 or count == 5:
					pares.append((i,j))
				elif count == 2: 
					if (i,j) in lista:
						pares.append((i,j))
				else:
					pass
	return pares

lista = leEntrada('file.txt')

print(simulaHexa(5,5,lista, 1))





