#include <cstdio>

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i*i <= n; ++i) {
		if (n % i == 0) {
			if (i*i != n) ans += i;
			ans += n / i;
		}
	}
	printf("%d", 5 * ans - 24);
	return 0;
}