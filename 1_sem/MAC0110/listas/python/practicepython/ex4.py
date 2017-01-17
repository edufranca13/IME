from math import sqrt

def is_divisible(number):
	res = list(filter(lambda x: number % x == 0, range(1, number//2 + 1)))
	return res

number = int(input('enter a number'))
print(is_divisible(number))


