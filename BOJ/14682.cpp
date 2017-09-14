#include <cstdio>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = n;
	while (k--) {
		n *= 10;
		ans += n;
	}
	printf("%d\n", ans);
	return 0;
}