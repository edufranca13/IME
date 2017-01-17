from datetime import date, timedelta

name, age = input("entre com nome e idade: ").split()

dif = timedelta(days=(100 - int(age)))

today = date.today()

date2 = today+dif

print(date2)