#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;

const int INF = 0x3F3F3F3F;

int a[501], n;
int partSum[501];
int dp[501][501];

int f(int s, int e) {
	// 하나는 합칠 수 없다.
	if (s == e) return 0;

	int& ret = dp[s][e];
	if (ret != -1) return ret;

	ret = INF;
	int part = partSum[e + 1] - partSum[s];
	for (int i = s; i < e; ++i) {
		ret = min(ret, part + f(s, i) + f(i + 1, e));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(partSum, 0, sizeof(partSum));
		memset(dp, -1, sizeof(dp));

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i) partSum[i] += partSum[i - 1] + a[i - 1];
		printf("%d\n", f(0, n - 1));
	}

	return 0;
}