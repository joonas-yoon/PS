#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[30001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int M[30001], m = 0;
	for (int i = 0; i < n; ++i) {
		m = max(m, a[i]);
		M[i] = m;
	}

	int ans = 0, len = 0;
	for (int i = 0; i < n; ++i) {
		if (M[i] <= a[i]) len = 0;
		len += M[i] > a[i];
		ans = max(ans, len);
	}
	printf("%d", ans);
	return 0;
}