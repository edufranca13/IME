def insertion_sort(lista):
	for i in range(len(lista)-1):
		if lista[i] > lista[i+1]:
			lista[i], lista[i+1] = lista[i+1], lista[i]
			while i >= 1:
				if lista[i] < lista[i-1]:
					lista[i], lista[i-1] = lista[i-1], lista[i]
				i -= 1
	return lista

l = [1,5,7,90,4,3,2,2,2,1,6,9,0,0,2]

print(insertion_sort(l))