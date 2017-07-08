#print ('\n'.join(s for s in map(lambda x: str(x), filter(lambda x: (x % 2 == 0), range(int(input())))))) 

# numList = []
# for i in range(50): 
# 	numList.append(i)

# prime = list(map(list, filter(lambda x, i: (x % i == 0 for i in range(2, int(50 ** 0.5) + 1)), numList)))
# print (prime)

# or x % i == 0 for i in range(3, int(x ** 0.5) + 1, 2)

isPrime = lambda x: 0 if ((x % 2 == 0 and x != 2) ^ x % i == 0 for i in range(3, int(x ** 0.5) + 1, 2)) else 1
print (isPrime(2))
for i in range(20): 
	print(str(i) + ": ", isPrime(i))