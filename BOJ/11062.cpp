#include <bits/stdc++.h>
using namespace std;

int a[1001], n;
int dp[1001][1001][2];

// [l, r] 에서 isM이 뽑을 때, 근우가 얻을 수 있는 최고의 점수
int solve(int l, int r, bool isM = false) {
	if (l > r) return 0;
	int& ret = dp[l][r][isM];
    if(ret != -1) return ret;
	int left = solve(l + 1, r, !isM);
	int right = solve(l, r - 1, !isM);
	if (isM) return ret = min(left, right);
	return ret = max(a[l] + left, a[r] + right);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
        memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		printf("%d\n", solve(0, n - 1));
	}
	return 0;
}