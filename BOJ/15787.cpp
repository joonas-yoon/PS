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

int setbit(int n, int k) {
	return n | (1 << k);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> v(n, 0);

	while (m--) {
		int cmd, i, x;
		scanf("%d %d", &cmd, &i);
		i--;

		if (cmd < 3) {
			scanf("%d", &x);
			x--;
		}

		if (cmd == 1) v[i] |= 1 << x;
		else if (cmd == 2) v[i] &= ~(1 << x);
		else if (cmd == 3) v[i] <<= 1;
		else v[i] >>= 1;
		v[i] &= ((1 << 20) - 1);
	}

	set<int> ans;
	for (int i = 0; i < n; ++i) {
		ans.insert(v[i]);
	}

	printf("%d\n", ans.size());

	return 0;
}