#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

bool solve(lld n, lld k) {
	vector<int> a;
	for (; n > 0; n /= k) a.push_back(n%k);
	for (int l = 0, r = (int)a.size() - 1; l < r; ++l, --r)
		if (a[l] != a[r]) return false;
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		lld a, n;
		scanf("%lld %lld", &a, &n);
		puts(solve(a, n) ? "1" : "0");
	}
	return 0;
}