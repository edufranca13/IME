from create_matrix import create_matrix, create_random_matrix


def transpose(A):
	B = create_matrix(len(A[0]), len(A))
	for i in range(len(A)):
		for j in range(len(A[0])):
			B[j][i] = A[i][j]
	return B

def transpose2(A):
	B = [[A[j][i] for j in range(len(A))] for i in range(len(A[0]))]
	return B


if __name__ =="__main__":

	a = create_random_matrix(3,3)
	print(a)
	b = transpose(a)
	print(b)

