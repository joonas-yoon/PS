#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int dp[302][302] = {};
	for (int x, y, i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		dp[y][x] = m - (x + y);
	}

	for (int i = 1; i <= 300; ++i) {
		dp[0][i] += dp[0][i - 1];
		dp[i][0] += dp[i - 1][0];
	}

	for (int i = 1; i <= 300; ++i) {
		for (int j = 1; j <= 300; ++j) {
			dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d", dp[300][300]);

	return 0;
}