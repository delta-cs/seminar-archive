def fact(n):
	result = 1
	if n == 0: return 1
	for num in range(2, n + 1):
		result *= num
	return result

n = int(input())

for i in range(n):
	k_n = int(input())
	if k_n < 0:
		print("Invalid input")
	else:
		print(fact(k_n))
