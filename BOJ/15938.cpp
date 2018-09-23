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

int dp[401][401][201];
set<ii> enemy;
int sx, sy, ex, ey, T;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

lld solve(int x, int y, int t) {
	int rx = sx + x, ry = sy + y;
	if (rx == ex && ry == ey) return 1;
	if (t >= T) return 0;
	if (t + dist(rx, ry, ex, ey) > T) return 0;

	int& ret = dp[x + 200][y + 200][t];
	if (ret != -1) return ret;
	ret = 0;

	FOR(d, 4) {
		int nx = x + dx[d], ny = y + dy[d];
		ii next(sx + nx, sy + ny);
		if (!enemy.count(next)) {
			ret = (ret + solve(nx, ny, t + 1)) % MOD;
		}
	}

	return ret;
}

int main() {
	int q;
	scanf("%d %d %d %d %d %d", &sx, &sy, &T, &ex, &ey, &q);
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		enemy.insert(make_pair(x, y));
	}

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", solve(0, 0, 0));

	return 0;
}