#include <cstdio>

typedef long long lld;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dp[101];

int solve(int n) {
	if (n <= 0) return n == 0;
	int& r = dp[n];
	if (r) return r;
	return r = (solve(n - 1) % MOD + solve(n - 2) % MOD) % MOD;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}