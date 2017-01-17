def bubble_sort(lista):
	for i in range(len(lista)):
		for j in range(len(lista)):
			if lista[i] < lista[j]:
				lista[i], lista[j] = lista[j], lista[i]
	return lista

l = [1,6,3,2,7,9,4,2]

print(bubble_sort(l))