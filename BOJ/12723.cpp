#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n, a[10], b[10];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		int ans = 0;
		for (int i = 0; i < n; ++i) ans += a[i] * b[n - 1 - i];
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}