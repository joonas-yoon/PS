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

map<string, int> failed;
map<string, bool> solved;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int qi, r, m, t, l, c;
		char name[25] = {};
		scanf("%d %s %d %d %d %d %d", &qi, name, &r, &m, &t, &l, &c);
		if ((solved[name] |= r == 4)) continue;
		else failed[name] += 1;
	}

	int solver = 0, fail = 0;
	for (auto& it : solved) {
		if (it.first == "megalusion") continue;
		if (it.second) {
			fail += failed[it.first];
			solver++;
		}
	}

	if (solver == 0) return puts("0"), 0;
	printf("%.12lf", solver / (solver + fail + 1e-12) * 100.);

	return 0;
}