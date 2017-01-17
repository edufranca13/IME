
#.n Eduardo Tsuyoshi Franca Hashimoto
#.u 6514136

from random import random
from math import cos, sin, pi, sqrt

def points_on_circle(r):
	alfa = 2*pi*random()
	res = [r*cos(alfa), r*sin(alfa)]
	return res

def points_in_circle(r):
	alfa = 2*pi*random()
	r1 = sqrt(random())*r
	res = [r1*cos(alfa), r1*sin(alfa)]
	return res

def dist(a, b):
	dist = 0
	for xa, xb in zip(a,b):
		dif = xa - xb
		dist += dif**2
	return sqrt(dist)

def metodo1(r,n):

	cont = 0.0
	L = r*sqrt(3)

	for i in range(n):
		a = points_on_circle(r)
		b = points_on_circle(r)
		distAB = dist(a,b)
		if distAB > L:
			cont += 1

	return cont/n


def metodo2(r,n):
	
	cont = 0.0

	for i in range(n):
		distOP = r*random()
		if distOP < r/2:
			cont += 1

	return cont/n

def metodo3(r,n):
	
	cont = 0.0
	o = [0,0]

	for i in range(n):
		p = points_in_circle(r)
		distOP = dist(p, o)
		if distOP < r/2:
			cont += 1

	return cont/n

def main():
	r = input('r: ')
	n = input('n: ')
	print('metodo1: ', metodo1(r,n))
	print('metodo2: ', metodo2(r,n))
	print('metodo3: ', metodo3(r,n))
main()

