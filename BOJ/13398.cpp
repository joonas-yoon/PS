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

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1, -INF);
	REP(i, 1, n) scanf("%d", &a[i]);
	vector<vector<int>> dp(2, vector<int>(n + 1, 0));
	int ans = 0;
	REP(i, 1, n) {
		dp[0][i] = max(dp[0][i - 1] + a[i], 0);
		dp[1][i] = max(dp[1][i - 1] + a[i], i >= 2 ? dp[0][i - 2] + a[i] : dp[0][i - 1]);
		ans = max({ ans, dp[0][i], dp[1][i] });
	}
	printf("%d\n", ans <= 0 ? *max_element(a.begin(), a.end()) : ans);
	return 0;
}