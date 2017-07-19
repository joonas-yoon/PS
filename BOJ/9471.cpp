#include <cstdio>

int pisano_period(int mod) {
	int a = 1, b = 1, c, k = 2;
	while (a % mod != 1 || b % mod != 0) {
		c = (a + b) % mod;
		a = b;
		b = c;
		k++;
	}
	return k;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int tcase, m;
		scanf("%d %d", &tcase, &m);
		printf("%d %d\n", tcase, pisano_period(m));
	}
	return 0;
}