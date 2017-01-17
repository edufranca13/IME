import config
from math import pi, cos, sin, degrees, acos, fabs, sqrt
from random import random

#extrai angulos ou raios da lista de cordas
#a = 1 -> angulos, a = 0 -> raios
def extract(lista, a):
	lista2 = list()
	for i in range(len(lista)):
		lista2.append(lista[i][0][a])
		lista2.append(lista[i][1][a])
	return lista2

#extrai angulos ou raios da lista de pontos medios
#a = 1 -> angulos, a = 0 -> raios
def extract_m(lista, a):
	return [lista[i][a] for i in range(len(lista))]

#encontra a chave a partir de um valor do dicionario. como valores iguais terao sempre a mesma chave 
#nao ha perigo de pegar a chave errada
def find_key(d, value):
	for keys in d:
		for v in d[keys]:
			if v == value:
				s = str(keys)
				return s
	return None

#classifica os angulos da lista de cordas em categorias de cores
def classify_a(lista):
	lista2 = lista[:]
	lista2.sort()

	d = dict()

	categories = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black', 'white']

	j = 0
	l = 0
	for j, cat in enumerate(categories):
		for i in range(l, len(lista2)):
			#compara o angulo com o trecho da divisao de 8 - pizza
			if lista2[i] <= 45*(j+1):
				if cat in d:
					#se a chave ja existe, append
					d[cat].append(lista2[i])
				else:
					#se a chave nao existe, cria como lista
					d[cat] = [lista2[i]]
				l += 1
	return d

#classifica os raios da lista de cordas em categorias de cores
def classify_r(lista):
	
	#converte em raios positivos
	lista2 = [fabs(lista[i]) for i in range(len(lista))]
	lista2.sort()

	d = dict()

	categories = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black', 'white']

	j = 0
	l = 0
	for j, cat in enumerate(categories):
		for i in range(l, len(lista2)):
			#compara o angulo com o trecho da divisao de 8 (coroas igualmente espacadas)
			if lista2[i] <= config.R*(j+1)/8:
				if cat in d:
					#se a chave ja existe, append
					d[cat].append(lista2[i])
				else:
					#se a chave nao existe, cria como lista
					d[cat] = [lista2[i]]
				l += 1
	return d

#classifica os raios da lista de cordas em categorias de cores
def classify_r2(lista):
	
	#converte em raios positivos
	lista2 = [fabs(lista[i]) for i in range(len(lista))]
	lista2.sort()

	d = dict()

	categories = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black', 'white']

	j = 0
	l = 0
	for j, cat in enumerate(categories):
		for i in range(l, len(lista2)):
			#compara o angulo com o trecho da divisao de 8 (coroas de mesma area)
			if lista2[i] <= config.R*sqrt(j+1)/sqrt(8):
				if cat in d:
					#se a chave ja existe, append
					d[cat].append(lista2[i])
				else:
					#se a chave nao existe, cria como lista
					d[cat] = [lista2[i]]
				l += 1
	return d