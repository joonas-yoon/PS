#include <bits/stdc++.h>
using namespace std;

int n;
int a[1002][1002];
int dp[1002][1002][3];

int solve(int y, int x, int k) {
	if (y < 0 || x < 0 || y >= n || x >= n) return 0;
	int& ret = dp[y][x][k];
	if (ret != -1) return ret;
	ret = 0;
	if (a[y][x] == k) {
		int nk = (k + 1) % 3;
		ret = 1 + max(solve(y + 1, x, nk), solve(y, x + 1, nk));
	}
	return ret = max({ ret, solve(y + 1, x, k), solve(y, x + 1, k) });
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0, 0));
	return 0;
}