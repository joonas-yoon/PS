#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int k, n;
lld dp[64][128];
lld solve(int t, int cm) {
	if (cm >= k) return 1LL << max(0, n - t);
	if (t >= n) return 0;
	lld& ret = dp[t][cm + 64];
	if (ret != -1) return ret;
	return ret = solve(t + 1, cm + 1) + solve(t + 1, cm - 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &k, &n);
	printf("%lld\n", (1LL << n) - solve(0, 0));
	return 0;
}