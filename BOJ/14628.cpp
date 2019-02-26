#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, k;
int mp[101], hp[101];
int dp[101][101];

// x번째 스킬을 사용했고, 남은 체력이 h일 때 사용되는 최소 마나 포인트
int solve(int x, int h) {
	if (x >= n) return h == 0 ? 0 : INF;

	int& ans = dp[x][h];
	if (ans != -1) return ans;

	ans = solve(x + 1, h);
	int cnt = 0, overload = 0;
	while(h >= hp[x]){
		h -= hp[x];
		overload += k * cnt;
		ans = min(ans, solve(x + 1, h) + overload + mp[x] * (cnt + 1));
		cnt++;
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int m;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &mp[i], &hp[i]);
	}

	printf("%d\n", solve(0, m));

	return 0;
}