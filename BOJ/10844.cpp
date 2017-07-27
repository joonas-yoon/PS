#include <cstdio>
#include <cstring>

const int MOD = 1e9;

// dp[n][k] := n번째 자리가 k일 때 나타날 수 있는 경우의 수
int dp[101][10];

int solve(int n, int k) {
	if (n < 1 || k < 0 || k > 9) return 0;
	if (n == 1) return 1;

	int& ret = dp[n][k];
	if (ret != -1) return ret;

	ret = 0;
	ret = (ret + solve(n - 1, k - 1)) % MOD;
	ret = (ret + solve(n - 1, k + 1)) % MOD;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i < 10; ++i)
		ans = (ans + solve(n, i)) % MOD;
	printf("%d", ans);
	return 0;
}