#include <bits/stdc++.h>
using namespace std;

using lld = long long;

lld solve(vector<int>& v, int l, int r) {
	if (l == r) return v[l];
	int mid = ((lld)l + r) / 2;
	int h = v[mid], left = mid, right = mid;
	lld area = h;
	while (l <= left - 1 || right + 1 <= r) {
		if (right + 1 > r || (l <= left - 1 && v[left - 1] > v[right + 1]))
			h = min(h, v[--left]);
		else
			h = min(h, v[++right]);
		area = max(area, h * (right - left + 1LL));
	}

	return max({
		area,
		solve(v, l, mid),
		solve(v, mid + 1, r)
	});
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	printf("%lld\n", solve(a, 0, n - 1));
	return 0;
}