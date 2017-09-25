#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int n, T[20], P[20];
int dp[20];

int solve(int cur) {
	if (cur >= n + 1) return cur == n + 1 ? 0 : -INF;
	if (cur + T[cur] > n + 1) return -INF;

	int& ret = dp[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = cur + T[cur]; i <= n; ++i) {
		ret = max(ret, solve(i));
	}
	return ret += P[cur];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d %d", &T[i], &P[i]);
	memset(dp, -1, sizeof(dp));
	T[0] = 1;
	printf("%d\n", solve(0));
	return 0;
}