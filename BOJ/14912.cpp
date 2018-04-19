#include <cstdio>

int main() {
	int n, k, f[10] = {};
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		for (int x = i; x > 0; x /= 10) f[x % 10]++;
	}
	printf("%d\n", f[k]);
	return 0;
}