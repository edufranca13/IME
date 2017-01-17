from create_matrix import create_random_matrix, create_matrix

def multiply(A,B):
	C = create_matrix(len(A), len(B[0]))
	for i in range(len(A)):
		for k in range(len(B[0])):
			s = 0
			for j in range(len(A[0])):
				s += A[i][j]*B[j][k]
			C[i][k] = s
	return C


	return C

if __name__ == "__main__":
	# A = create_random_matrix(3, 4)
	# B = create_random_matrix(4, 2)

	# print(A, B)

	# C = multiply(A,B)
	# print(C)

	D = create_matrix(3,3)
	D[0][0] = 12
	D[0][1] = 7
	D[0][2] = 3
	D[1][0] = 4
	D[1][1] = 5
	D[1][2] = 6
	D[2][0] = 7
	D[2][1] = 8
	D[2][2] = 9

	E = create_matrix(3, 4)
	E[0][0] = 5
	E[0][1] = 8
	E[0][2] = 1
	E[0][3] = 2
	E[1][0] = 6
	E[1][1] = 7
	E[1][2] = 3
	E[2][0] = 4
	E[2][1] = 5
	E[2][2] = 9
	E[2][3] = 1

	print(D, E)

	F = multiply(D,E)
	print(F)

	