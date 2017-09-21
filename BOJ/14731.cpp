#include <cstdio>

using lld = long long;

const lld MOD = 1e9 + 7;

lld modPowers(lld a, lld n, lld mod) { // a^n % mod
	lld ret = 1LL;
	while (n) {
		if (n % 2) ret = (ret * a) % mod;
		n /= 2LL;
		a = (a * a) % mod;
	}
	return ret;
}

int main() {
	int n;
	lld fr[100001], po[100001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld %lld", &fr[i], &po[i]);
	lld ans[100001] = {};
	for (int i = 0; i < n; ++i) {
		if (po[i] > 0) {
			ans[i] = ((fr[i] % MOD) * (po[i] % MOD)) % MOD;
			ans[i] = (ans[i] * modPowers(2LL, po[i] - 1, MOD)) % MOD;
		}
	}
	lld res = 0;
	for (int i = 0; i < n; ++i) res = (res + ans[i]) % MOD;
	printf("%lld\n", res);
	return 0;
}