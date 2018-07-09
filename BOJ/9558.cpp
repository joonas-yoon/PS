#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, a[1001];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		scanf("%d", &m);
		int ans = INF;
		for (int x, i = 0; i < m; ++i) {
			scanf("%d", &x);
			for (int j = 0; j < n; ++j) ans = min(ans, abs(x - a[j]));
		}
		printf("%d\n", ans);
	}

	return 0;
}