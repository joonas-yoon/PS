#include <bits/stdc++.h>
using namespace std;

using lld = long long;

lld balloons(vector<int>& a, lld mid) {
	lld times = 0;
	for (auto& x : a)
		times += mid / (lld)x;
	return times;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	lld lo = 0, hi = 1000000LL * m;
	while (lo <= hi) {
		lld mid = (lo + hi) / 2LL;
		lld g = balloons(a, mid);
		if (m <= g)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	printf("%lld\n", lo);
	return 0;
}