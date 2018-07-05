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

int n, h;
bool v[30][10];

bool solved() {
	vector<int> a(n);
	FOR(i, n) a[i] = i;

	FOR(r, h) {
		FOR(c, n) {
			if (v[r][c])
				swap(a[c], a[c + 1]);
		}
	}

	FOR(i, n - 1) {
		if (a[i] != a[i + 1] - 1)
			return false;
	}
	return true;
}

void solve(int cur, int k, int use) {
	if (k == use) {
		if (solved()) {
			cout << k << '\n';
			exit(0);
		}
		return;
	}

	int row = cur / n, col = cur % n;
	if (cur >= n * h) return;

	solve(cur + 1, k, use);

	if (col != n - 1 && !v[row][col]) {
		bool able = true;
		if (col > 0) able &= !v[row][col - 1];
		able &= !v[row][col + 1];
		if (able) {
			v[row][col] = true;
			solve(cur + 1, k + 1, use);
			v[row][col] = false;
		}
	}
}

int main() {
	fastio();

	int m;
	cin >> n >> m >> h;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1][b - 1] = true;
	}

	FOR(n_use, 4) {
		solve(0, 0, n_use);
	}
	cout << -1 << '\n';

	return 0;
}