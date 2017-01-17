def contaVizinhosVivos(i, j, pares, m, n):
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


a = open('file.txt')
pares = list()

for line in a:
	l = line.strip()
	if len(l) == 1:
		if l == 'Q':
			print('grade quadrada')
			continue
		elif l =='H':
			print('grade hexagonal')
			continue

	x,y = l.split(',')
	pares.append((int(x),int(y)))

print(pares)

# for i in range(5):
# 	for j in range(5):
# 		count = contaVizinhosVivos(i,j, pares, 5, 5)
# 		print("(%d, %d) tem %d vizinhos" % (i, j, count))
# 		if count == 3:
# 			if (i, j) in pares:
# 				print('Sobrevive')
# 			else:
# 				pares.append((i,j))
# 		elif count == 2: 
# 			if (i,j) in pares:
# 				print('Sobrevive')
# 		else:
# 			if (i,j) in pares:
# 				pares.remove((i,j))

# print(pares)

pares2 = list()

for i in range(5):
	for j in range(5):
		count = contaVizinhosVivos(i,j, pares, 5, 5)
		# print("(%d, %d) tem %d vizinhos" % (i, j, count))
		if count == 3:
			pares2.append((i,j))
		elif count == 2: 
			if (i,j) in pares:
				pares2.append((i,j))
		else:
			pass

print(pares2)


