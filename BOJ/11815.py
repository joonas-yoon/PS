def issquare(n):
    return int(n ** 0.5) ** 2 == n

n = input()
a = map(int, raw_input().split())
for x in a:
	print 1 if issquare(x) else 0,
