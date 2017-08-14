#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int l, int r) {
	if (l == r) return v[l];
	int mid = (l + r) / 2;
	int h = v[mid], left = mid, right = mid;
	int area = h;
	while (l <= left - 1 || right + 1 <= r) {
		if (right + 1 > r || (l <= left - 1 && v[left - 1] > v[right + 1]))
			h = min(h, v[--left]);
		else
			h = min(h, v[++right]);
		area = max(area, h * (right - left + 1));
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
	for (auto& x : a) scanf("%d", &x);
	printf("%d\n", solve(a, 0, n - 1));
	return 0;
}
