#include <cstdio>

using lld = long long;

lld dp[50];
lld f(int n) {
	if (n == 0) return 1;
	lld& ret = dp[n];
	if (ret) return ret;
	ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += f(i) * f(n - 1 - i);
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", f(n));
	return 0;
}