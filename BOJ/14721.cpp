#include <cstdio>

using lld = long long;

lld f(int x, int a, int b) {
	return (lld)a*x + b;
}

int main() {
	int n, Xs[101], Ys[101];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &Xs[i], &Ys[i]);
	lld res = 1LL << 62;
	int ax, ay;
	for (int a = 1; a <= 100; ++a) {
		for (int b = 1; b <= 100; ++b) {
			lld sum = 0;
			for (int i = 0; i < n; ++i) {
				lld ai = Ys[i] - f(Xs[i], a, b);
				sum += ai * ai;
			}
			if (res > sum) {
				res = sum;
				ax = a;
				ay = b;
			}
		}
	}
	printf("%d %d\n", ax, ay);
	return 0;
}