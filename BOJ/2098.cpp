#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int n, a[16][16];
int dp[16][1<<17];

int tsp(const int& start, int cur, int bit, bool first = true) {
	if (!first && start == cur) {
		if (bit & ((1 << n) - 1) == bit) return 0;
		return INF;
	}

	int& ret = dp[cur][bit];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < n; ++i) {
		if (a[cur][i] == 0 || bit & (1 << i)) continue;
		ret = min(ret, a[cur][i] + tsp(start, i, bit | (1 << i), false));
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", tsp(0, 0, 0));

	return 0;
}