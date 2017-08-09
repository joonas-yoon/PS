#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, ans = 0;
		scanf("%d", &n);
		while (n > 0) {
			ans += n / 5;
			n /= 5;
		}
		printf("%d\n", ans);
	}
	return 0;
}