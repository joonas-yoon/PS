#include <cstdio>

int main() {
	int a, b;
	const int mod = 14579;
	scanf("%d %d", &a, &b);
	int sum = 0, ans = 1;
	for (int k = 1; k < a; ++k) sum = (sum + k) % mod;
	for (int i = a; i <= b; ++i) {
		sum = (sum + i) % mod;
		ans = (ans * sum) % mod;
	}
	printf("%d", ans);
	return 0;
}