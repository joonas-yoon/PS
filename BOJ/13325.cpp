#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int h, n;
lld a[(1 << 21) + 1];

lld depth(int cur) {
	if (cur > n) return 0;
	int left = 2 * cur + 1;
	int right = 2 * cur + 2;
	lld l = depth(left), r = depth(right);
	if (l > r) {
		a[right] += l - r;
	}
	else if (l < r) {
		a[left] += r - l;
	}
	return a[cur] + max(l, r);
}

int main() {
	scanf("%d", &h);
	n = 2 * ((1 << h) - 1);
	for (int i = 1; i <= n; ++i) scanf("%lld ", &a[i]);
	depth(0);
	lld ans = 0;
	for (int i = 1; i <= n; ++i) ans += a[i];
	printf("%lld\n", ans);
	return 0;
}