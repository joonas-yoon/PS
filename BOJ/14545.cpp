#include <cstdio>
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += i*i;
		}
		printf("%d\n", ans);
	}
	return 0;
}