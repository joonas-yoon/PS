#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& a, int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) return 0;
	if (left == right) return a[mid];
	int sum = a[mid], l = mid, r = mid, h = a[mid];
	while (left <= l - 1 || r + 1 <= right) {
		if ( !(left <= l - 1) || (r + 1 <= right && a[l - 1] < a[r + 1]) ) {
			h = min(h, a[++r]);
		}
		else {
			h = min(h, a[--l]);
		}
		sum = max(sum, h * (r - l + 1));
	}
	return max({
		sum,
		solve(a, left, mid),
		solve(a, mid + 1, right)
	});
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		printf("%d\n", solve(a, 0, a.size() - 1));
	}
	return 0;
}