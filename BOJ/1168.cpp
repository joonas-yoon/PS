#include <bits/stdc++.h>
using namespace std;

using lld = long long;

lld t[400100], n;

void build() {
	for (int i = n - 1; i > 0; --i) {
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
}

void update(int i, lld val) {
	for (t[i += n] = val; i > 1; i >>= 1) {
		t[i >> 1] = t[i] + t[i ^ 1];
	}
}

lld query(int l, int r) { // [l, r)
	lld sum = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum += t[l++];
		if (r & 1) sum += t[--r];
	}
	return sum;
}

int main() {
	int n1, k;
	scanf("%d %d", &n1, &k);
	n = n1 * 2;
	for (int i = 0; i < n; ++i) t[n + i] = 1;
	build();
	vector<int> ans;
	for (int width = n1 - 1, cur = k - 1; width >= 0; --width) {
		cur = (cur + n1) % n1;
		ans.push_back(cur);
		if (width < 1) break;
		update(cur, 0);
		update(cur + n1, 0);
		int kth = (k - 1) % width + 1;
		int l = cur, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			lld sum = query(cur, mid);
			if (sum < kth) l = mid + 1;
			else r = mid - 1;
		}
		cur = l - 1;
	}

	printf("<");
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", ans[i] + 1);
		if (i + 1 != ans.size()) printf(", ");
	}
	puts(">");
	return 0;
}