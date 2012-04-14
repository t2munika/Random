ways = 1;

for i in range(2, 41):
	ways = ways * i

for j in range(0, 2):
	for i in range(2, 21):
		ways = ways / i

print ways

