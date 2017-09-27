#include <bits/stdc++.h>
using namespace std;

int n, a[2][100001];
int dp[2][100001];

int solve(int y, int x) {
	if (x >= n) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;

	ret = 0;
	return ret = max(
		a[y][x] + solve(!y, x + 1),
		solve(y, x + 1)
	);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int b = 0; b < 2; ++b) {
			for (int i = 0; i < n; ++i) {
				scanf("%d", &a[b][i]);
			}
		}

		memset(dp, -1, sizeof(dp));
		printf("%d\n", max(solve(0, 0), solve(1, 0)));
	}
	return 0;
}