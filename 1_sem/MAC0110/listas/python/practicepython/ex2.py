def odd_or_even(n):
	if n % 2 == 0:
		return "Even"
	else:
		return "Odd"

def odd_or_even_enhanced(n):
	if n % 4 == 0:
		return "Even and divisible for 4"
	elif n % 2 == 0:
		return "Even"
	else:
		return "Odd"

def divisible(num, check):
	if num % check == 0:
		return "{:.2f} is divisible by {:.2f}".format(num, check)
	else:
		return "{:.2f} is not divisible by {:.2f}".format(num, check)

n = int(input("Enter a number: "))
print(odd_or_even_enhanced(n))

n, check = (input('enter two numbers: ')).split()
print(divisible(float(n), float(check)))

