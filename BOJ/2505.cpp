#include <bits/stdc++.h>
using namespace std;

void _reverse(vector<int>& a, vector<int>& p, int l, int r) {
	if (l > r) swap(l, r);
	for (; l < r; ++l, --r) {
		swap(a[l], a[r]);
		swap(p[a[l]], p[a[r]]);
	}
}

bool solve(vector<int> a, vector<int> p, int inc = 1) {
	int cnt = 0, n = a.size();
	int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	for (int i = inc < 0 ? n - 1 : 0; i >= 0 && i < n; i += inc) {
		if (a[i] != i + 1) {
			cnt += 1;
			if (cnt == 1)
				a1 = i, a2 = p[i + 1];
			else if (cnt == 2)
				b1 = i, b2 = p[i + 1];
			else
				return false;
			_reverse(a, p, i, p[i + 1]);
		}
	}
	if (a1 > a2) swap(a1, a2);
	if (b1 > b2) swap(b1, b2);
	printf("%d %d\n%d %d\n", 1 + a1, 1 + a2, 1 + b1, 1 + b2);
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), pos(n + 1, 0);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]), pos[a[i]] = i;

	vector<int> ta = a, tp = pos;
	if (!solve(a, pos)) {
		solve(ta, tp, -1);
	}

	return 0;
}