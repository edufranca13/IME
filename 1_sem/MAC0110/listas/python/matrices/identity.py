from create_matrix import create_matrix

def create_identity(size):
	m = create_matrix(size, size)
	for i in range(len(m)):
		for j in range(len(m[i])):
			if i == j:
				m[i][j] = 1
	return m

def isIdentity(matrix):
	#verify if it is square
	for i in range(len(matrix)):
		if(len(matrix[i]) != len(matrix)):
			return False
	#verify if the diagonal is one
	for i in range(len(matrix)):
		for j in range(len(matrix[i])):
			if i == j:
				if matrix[i][j] != 1:
					return False
			else:
				if matrix[i][j] != 0:
					return False
	return True


if __name__ == "__main__":

	m = create_identity(3)
	print(m)
	print(isIdentity(m))


	m[1][2] = 2
	print(m)
	print(isIdentity(m))

	m[1][2] = 0
	m[2][2] = 2
	print(m)
	print(isIdentity(m))

	