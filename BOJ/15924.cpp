#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;

const lld MOD = 1e9 + 9;

int h, w;
int dp[3001][3001];
char s[3001][3001];

int solve(int i, int j) {
	if (i < 0 || i >= h || j < 0 || j >= w) return 0;
	if (i == h - 1 && j == w - 1) return 1;

	int& ret = dp[i][j];
	if (ret != -1) return ret;

	ret = 0;
	char c = s[i][j];
	if (c != 'S') ret = (ret + solve(i, j + 1)) % MOD;
	if (c != 'E') ret = (ret + solve(i + 1, j)) % MOD;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &h, &w);
	FOR(i, h) scanf("%s ", s[i]);
	int ans = 0;
	FOR(i, h) FOR(j, w)
		ans = (ans + solve(i, j)) % MOD;
	printf("%d\n", ans);
	return 0;
}