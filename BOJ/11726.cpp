#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;

int dp[1002];

int solve(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	int& ret = dp[n];
	if (ret != -1) return ret;
	return (ret = (solve(n - 1) + solve(n - 2)) % mod);
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	printf("%d\n", solve(n));
	return 0;
}