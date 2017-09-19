#include <bits/stdc++.h>
using namespace std;

int n;
int a[1002];
int dp[1002][3];

int solve(int x, int k) {
    if (x >= n) return 0;
	int& ret = dp[x][k];
	if (ret != -1) return ret;
	ret = solve(x+1, k);
	if (a[x] == k) ret = max(ret, 1 + solve(x + 1, (k + 1) % 3));
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0));
	return 0;
}