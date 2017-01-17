def selection_sort(lista):
	for j in range(len(lista)):
		for i in range(len(lista)-1):
			if lista[i] > lista[i+1]:
				lista[i], lista[i+1] = lista[i+1], lista[i]
	return lista

l = [1,67,3,2,6,9,4,2,4,7,0]

print(selection_sort(l))