from create_matrix import create_matrix, create_random_matrix, is_same_size

def add(A, B):
	if not is_same_size(A,B):
		return 'Error - can`t sum matrices of different sizes'
	else:
		C = create_matrix(len(A), len(A[0]))
		for i in range(len(A)):
			for j in range(len(A[0])):
				C[i][j] = A[i][j] + B[i][j]
				return C


def add2(A,B):
	if not is_same_size(A,B):
		return "Error"
	else:
		C = [[A[i][j]+B[i][j] for j in range(len(A[0]))] for i in range((len(A)))]
		return C

if __name__ == "__main__":
	A = create_random_matrix(3,3)
	B = create_random_matrix(3,3)

	print(A, B)

	C = add(A,B)

	print(C)