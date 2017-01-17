from random import randint

#creates a matrix(i,j) filled with zeros
def create_matrix(size_i, size_j):
	matrix = [[0 for j in range(size_j)] for i in range(size_i)]
	return matrix

def create_random_matrix(size_i, size_j):
	matrix = [[randint(0,2) for j in range(size_j)] for i in range(size_i)]
	return matrix

def is_same_size(A,B):
	if len(A) != len(B):
		return False
	elif len(A[0]) != len(B[0]):
		return False
	else:
		return True

if __name__ == "__main__":
	print(create_matrix(3,3))
	print(create_random_matrix(3,3))

	a = create_matrix(3,4)
	b = create_random_matrix(4,3)
	c = create_random_matrix(2,1)
	d = create_random_matrix(2,1)
	e = create_matrix(2,2)

	print(is_same_size(a,b))
	print(is_same_size(a,c))
	print(is_same_size(a,d))
	print(is_same_size(a,e))
	print(is_same_size(b,d))
	print(is_same_size(b,e))
	print(is_same_size(e,c))
	print(is_same_size(e,d))
	print(is_same_size(d,c)) #True
	print(is_same_size(c,d)) #True



