#include <cstdio>

int gcd(int p, int q) { return q ? gcd(q, p%q) : p; }

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = 1, m = gcd(a, b); i <= m; ++i) {
		if (a % i || b % i) continue;
		printf("%d %d %d\n", i, a / i, b / i);
	}
	return 0;
}