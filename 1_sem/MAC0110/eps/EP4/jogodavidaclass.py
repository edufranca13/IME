class JogoDaVida():

	def __init__(self):

		self.tipo = None
		self.estado = list()

	def leEntrada(self, fileName):
		oFile = open(fileName)

		for line in oFile:
			l = line.strip()
			if len(l) == 1:
				if l == 'Q':
					self.tipo = l
					continue
				elif l =='H':
					self.tipo = l
					continue

			x,y = l.split(',')
			self.estado.append((int(x),int(y)))

	def countNeighbours(self, i, j, m, n):
		count = 0
		for k in range(-1,2):
			for l in range(-1,2):
				if self.tipo=='Q' and (k == 0 and l == 0):
					continue
				elif self.tipo=='H' and (k == 0 and l == 0 or (j % 2 != 0 and (k== 1 and l == -1 or k == 1 and l == 1)) or j % 2 == 0 and ((k == -1 and l == -1 or k == -1 and l == 1))):
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
					if (x,y) in estado:
						count += 1

		return count



if __name__ == "__main__":

	jogo1 = JogoDaVida()
	jogo1.leEntrada('file.txt')
	print(jogo1.estado)
