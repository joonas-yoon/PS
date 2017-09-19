#include <cstdio>

using lld = long long;

lld f(int a[], int n, lld x) {
	lld ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += (lld)a[i] / x;
	}
	return ret;
}

int main() {
	int n, k, a[10001];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	lld l = 0, r = 1LL << 33;
	while (l <= r) {
		lld mid = (l + r) / 2;
		if (f(a, n, mid) >= k) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", r);
	return 0;
}