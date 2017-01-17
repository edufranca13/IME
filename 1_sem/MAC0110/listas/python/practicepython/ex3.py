def less_than(l, p):
	r = list()
	for number in l:
		if number < p:
			r.append(number)
	return r

def less_than2(l, p):
	r = [l[i] for i in range(len(l)) if l[i] < 5]
	return r


if __name__ =="__main__":
	lista = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
	print(less_than(lista, 5))

	print(less_than2(lista, 5))

	a = list(filter(lambda x: x < 5, lista))
	print(a)

	for a in filter(lambda x: x % 2 == 0, lista):
		print(a)