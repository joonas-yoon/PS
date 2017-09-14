#include <cstdio>
typedef long long lld;
int main() {
	int n, tc = 0;
	while (~scanf("%d", &n) && n) {
		lld ans = 0;
		for (int i = 0; i < n; ++i) {
			for (lld x, j = 0; j <= i; ++j) {
				scanf("%lld", &x);
				if (i == n - 1 || j == 0 || j == i) ans += x;
			}
		}
		printf("Case #%d:%lld\n", ++tc, ans);
	}
	return 0;
}