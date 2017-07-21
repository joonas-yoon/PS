#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int n;
ii works[1001];

int dp[1001][1001];

int solve(int idx, int day) {
	if (idx >= n) return 0;

	int& ret = dp[idx][day];
	if (ret != -1) return ret;

	ret = solve(idx + 1, day);
	if (day <= works[idx].first)
		ret = max(ret, works[idx].second + solve(idx + 1, day + 1));
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &works[i].first, &works[i].second);
	sort(works, works + n);
	printf("%d", solve(0, 1));
	return 0;
}