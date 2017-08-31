#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[100001][10];

int solve(int k, int n) {
	if (k <= 0) return k == 0;
	int& ret = dp[k][n];
    if(ret != -1) return ret;
    ret = 0;
	for (int i = n; i < 10; ++i) {
		ret = (ret + solve(k - 1, i)) % MOD;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--) {
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < 10; ++i)
			ans = (ans + solve(n - 1, i)) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}