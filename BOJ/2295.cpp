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

int main() {
	int n;
	scanf("%d", &n);
	vector<lld> a(n);
	for (auto& x : a) scanf("%lld ", &x);
	sort(all(a));

	vector<lld> xyz; // x+y
	vector<ll> kmz; // {k-z, k}
	for (int x = 0; x < n; ++x)
		for (int y = x; y < n; ++y)
			xyz.push_back(a[x] + a[y]);

	for (int z = 0; z < n; ++z)
		for (int k = z; k < n; ++k)
			kmz.push_back(ll(a[k] - a[z], a[k]));

	sort(all(xyz));
	xyz.erase(unique(all(xyz)), xyz.end());
	sort(all(kmz));
	kmz.erase(unique(all(kmz)), kmz.end());

	lld ans = 0;
	for (auto& kz : kmz) {
		if (std::binary_search(all(xyz), kz.first))
			ans = max(ans, kz.second);
	}
	printf("%lld\n", ans);
    return 0;
}