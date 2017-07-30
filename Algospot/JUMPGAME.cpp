#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, a[101][101];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);

		int dp[101][101] = {};
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int ny = i + a[i][j], nx = j + a[i][j];
				if (ny < n) dp[ny][j] += dp[i][j];
				if (nx < n) dp[i][nx] += dp[i][j];
			}
		}
		puts(dp[n - 1][n - 1] ? "YES" : "NO");
	}
	return 0;
}