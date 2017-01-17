
def vetoriza(s):
	return s.split(" ")

def bigV(s, colunas):
	v = vetoriza(s)
	v2 = []
	v3 = []
	comp = 0
	k = 0
	for i in range(len(v)):
		comp += len(v[i]) + 1
		if comp > colunas:
			for j in range(k, i):
				v2.append(v[j])
			if v2:
				v3.append(v2)
			v2 = []
			k = i
			comp = len(v[i])

	for i in range(k, len(v)):
		v2.append(v[i])
	v3.append(v2)
	return v3

def justifica(s, colunas):
	v = bigV(s, colunas)
	print(v)
	for frase in v:
		N = colunas - len(frase) + 2
		for w in frase:
			N -= len(w)
		esp1 = 1 + N//(len(frase) - 1)
		esp2 = N % (len(frase) - 1) - 1
		N = 0
		for i in range(len(frase)):
			print(frase[i])
			for j in range(esp1):
				print("_")
			if i > len(frase) - esp2:
				print("_")
	

s = "38:1 Then the LORD answered Job out of the whirlwind, and said, 38:2 Who is this that darkeneth counsel by words without knowledge?  38:3 Gird up now thy loins like a man;for I will demand of thee, and answer thou me."
justifica(s, 65)

