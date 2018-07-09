#include <cstdio>

int gcd(int p, int q) { return q ? gcd(q, p%q) : p; }

int main() {
	int n, m;
	while (~scanf("%d %d ", &n, &m))
		printf("%10d%10d %s Choice\n\n", n, m, gcd(n, m) != 1 ? "Bad" : "Good");
	return 0;
}