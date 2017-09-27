#include <bits/stdc++.h>
using namespace std;

using lld = long long;

// 크기 n인 상황에서, val은 몇번째인가?
lld nth(int n, lld val) {
	lld r = 0;
	for (lld i = 1; i <= val && i <= n; ++i) {
		if (val >= i * n) r += n;
		else r += val / i;
	}
	return r;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	lld l = 1, r = (lld)n*n;
	while (l <= r) {
		lld mid = (l + r) / 2LL;
		lld x = nth(n, mid);
		if (k <= x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}