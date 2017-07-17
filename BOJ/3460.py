for _ in range(int(input())):
	n = int(input())
	d = 0
	while (2 ** d) <= n:
		if n & (2 ** d) != 0:
			print(d, end=" ")
		d += 1
	print()
