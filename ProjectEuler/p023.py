x = 1
sum = 0

for i in range(1,101):
	x = x * i

while x > 0:
	sum = sum + (x % 10)
	x = x / 10

print sum
