#include <cstdio>

int main() {
	int n, x, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		bool isPrime = x >= 2;
		for (int i = 2; isPrime && i*i <= x; ++i) {
			isPrime &= x % i != 0;
		}
		ans += isPrime;
	}
	printf("%d", ans);
	return 0;
}