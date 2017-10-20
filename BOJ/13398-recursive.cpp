#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int n, a[100005];
int dp[100005][2][2];

int solve(int cur, bool selected, int removed = 0) {
	if (cur >= n) return 0;
	int& ret = dp[cur][selected][removed];
	if (ret != -INF) return ret;

	ret = 0;
	if(removed == 0) ret = max(ret, solve(cur + 1, selected, removed + 1));
	ret = max(ret, a[cur] + solve(cur + 1, true, removed));
	if (!selected) ret = max(ret, solve(cur + 1, false, removed));
	return ret;
}


int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d", &a[i]);
	FOR(i, n) FOR(j, 2) FOR(k, 2) dp[i][j][k] = -INF;
	int ans = max(solve(0, 1), solve(0, 0));
	printf("%d\n", ans <= 0 ? *max_element(a, a+n) : ans);
	return 0;
}