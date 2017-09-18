#include <bits/stdc++.h>
using namespace std;

int diff(vector<int>& a, vector<int> &b) {
	int ret = 0;
	for (auto& x : a) {
		ret += !binary_search(b.begin(), b.end(), x);
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	printf("%d", diff(a, b) + diff(b, a));
	return 0;
}