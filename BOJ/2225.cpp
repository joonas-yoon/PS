#include <cstdio>
#include <cstring>

const int MOD = 1e9;

int dp[201][201];

int f(int n, int k) {
	if (k == 1) return 1;
	int& ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n; ++i) {
		ret = (ret + f(n - i, k - 1)) % MOD;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", f(n, k));
	return 0;
}