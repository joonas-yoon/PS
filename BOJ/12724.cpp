#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n, a[1000], b[1000];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		lld ans = 0;
		for (int i = 0; i < n; ++i) ans += (lld)a[i] * b[n - 1 - i];
		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}