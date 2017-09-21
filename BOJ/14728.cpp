#include <bits/stdc++.h>
using namespace std;

using lld = long long;

const int INF = 0x3F3F3F3F;

int n, times[101], point[101];
lld dp[101][10005];
lld f(int cur, int k) {
	if (k < 0) return -INF;
	if (cur >= n) return 0;
	lld& ret = dp[cur][k];
	if (ret != -1) return ret;
	ret = f(cur + 1, k);
	return ret = max(ret, (lld)point[cur] + f(cur + 1, k - times[cur]));
}

int main() {
	int t;
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &times[i], &point[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", f(0, t));
	return 0;
}