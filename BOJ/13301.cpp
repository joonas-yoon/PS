#include <cstdio>

using lld = long long;

lld a[90];

lld f(int n) {
	return (a[n - 1] + 2LL * a[n]) * 2;
}

int main() {
	a[0] = 0, a[1] = 1;
	for (int i = 2; i < 90; ++i) a[i] = a[i - 1] + a[i - 2];

	int n;
	scanf("%d", &n);
	printf("%lld\n", f(n));
	return 0;
}