def solve(s):
	for i in ["pi", "ka", "chu"]:
		s = s.replace(i, '.')
	return s.replace('.', '')
print("YES" if solve(input()) == '' else "NO")