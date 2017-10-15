#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	if (k == 1) {
		sort(a.begin(), a.end());
		printf("%d\n", a.front());
		return 0;
	}
	int ans = -2e9+1;
	for (int i = 0; i < n; ++i) {
		int g = i == 0 || i == n - 1 ? 2 : 3;
		if (k >= g) ans = max(ans, a[i]);
	}
	printf("%d\n", ans);
	return 0;
}