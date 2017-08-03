#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e7;

int dp[101][101];

// 앞으로 n개의 블럭이 남았고, 가장 위에 쌓은 면이 k개일 때 가능한 가짓 수
int solve(int n, int k) {
	if (n == 0) return 1;

	int& ret = dp[n][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; n - i >= 0; ++i) {
		int len = (k + i - 1) % MOD;
		int sub = solve(n - i, i) % MOD;
		ret = (ret + len * sub) % MOD;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = (ans + solve(n - i, i)) % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}