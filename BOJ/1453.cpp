#include <cstdio>

int main() {
	int n, x, f[150] = {};
	scanf("%d", &n);
	int ans = 0;
	while (n--) {
		scanf("%d", &x);
		ans += f[x];
		f[x] = 1;
	}
	printf("%d\n", ans);
	return 0;
}