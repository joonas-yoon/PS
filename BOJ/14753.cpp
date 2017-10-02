#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (auto& x : a) scanf("%d", &x);
	sort(a.begin(), a.end());
	int fir = a[0] * a[1], lst = a[n - 2] * a[n - 1];
	int m2 = max(fir, lst);
	int m3 = max({
		fir * a[2],
		fir * a[n - 1],
		a[0] * lst,
		a[n-3] * lst
	});
	printf("%d\n", max(m2, m3));
	return 0;
}