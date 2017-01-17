a = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
b = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]

c = list(filter(lambda x: x in a and x in b, b))

print(c)

c = set.intersection(set(a), set(b))
print(c)