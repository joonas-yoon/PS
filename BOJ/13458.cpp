#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	int n, b, c;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	scanf("%d %d", &b, &c);
	
	lld ans = 0;
	for (int i = 0; i < n; ++i) {
		if (b >= c || a[i] >= b) {
			ans++;
			a[i] -= b;
		}
		a[i] = max(0, a[i]);
		ans += (a[i] + c - 1LL) / c;
	}
	printf("%lld", ans);

	return 0;
}