#include <bits/stdc++.h>
using namespace std;

#define fastio() std::cin.tie(NULL);std::ios::sync_with_stdio(false)
#define all(v) (v).begin(),(v).end()
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

lld pair_sum(ll p) { return p.first + p.second; }

ll min_sum(ll a, ll b) {
	if (abs(pair_sum(a)) > abs(pair_sum(b)))
		return b;
	return a;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<lld> a(n);
	FOR(i, n) scanf("%lld ", &a[i]);
	sort(all(a));
	ll ans = { a[0], a[1] };
	FOR(i, n) {
		lld x = a[i];
		auto it = std::lower_bound(all(a), -x);
		if (it != a.end() && *it != x) {
			ans = min_sum(ans, make_pair(x, *it));
		}
		if (it != a.begin()) {
			it--;
			if (*it != x)
				ans = min_sum(ans, make_pair(x, *it));
		}
	}
	if (ans.first > ans.second) swap(ans.first, ans.second);
	printf("%lld %lld\n", ans.first, ans.second);
	return 0;
}