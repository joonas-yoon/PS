#include <bits/stdc++.h>
using namespace std;

#define fastio() setbuf(stdout, NULL);std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;
const double EPS = 1e-12;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {-1, 0, 1, 0};

typedef long long lld;

int n, days;
ii plan[1005];
vector<int> adj[1005];
int dp[1005];

int solve(int cur) {
	if (cur >= n) return 0;

	int& ret = dp[cur];
	if (ret != -1) return ret;

	int start = plan[cur].first, end = plan[cur].second;
	ret = days - end;
	for (auto& next : adj[cur]) {
		ret = min(ret, max(plan[next].first - end - 1, solve(next)));
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &days, &n);

	plan[0] = make_pair(0, 0);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &plan[i].first, &plan[i].second);
	}
	plan[n + 1] = make_pair(days + 1, days + 1);
	n += 2;
	sort(plan, plan + n);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (plan[i].second < plan[j].first) {
				adj[i].push_back(j);
			}
		}
	}

	printf("%d\n", solve(0));

	return 0;
}