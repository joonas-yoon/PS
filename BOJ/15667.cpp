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

static int dx[] = { 0, 1, 0, -1 };
static int dy[] = { -1, 0, 1, 0 };

int main() {
	lld k;
	scanf("%lld", &k);
	for (lld x = 1; x <= k; ++x) {
		if (1 + x + x * x == k) return printf("%lld\n", x), 0;
	}
	return 0;
}