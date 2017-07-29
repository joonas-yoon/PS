#include <cstdio>

int main() {
	int ans = 0, n;
	scanf("%d", &n);
	for (int x, i = 1; i <= n; ++i) {
		scanf("%d", &x);
		ans += x != i;
	}
	printf("%d", ans);
	return 0;
}