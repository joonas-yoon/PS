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
const lld MOD = 1e9 + 9;
const double EPS = 1e-12;

static int dx[] = {0, 0, -1, 0};
static int dy[] = {-1, 1, 0, 0};

int n, k;

int tree[2001000];

int main() {
	int pos;
	scanf("%d %d %d", &n, &k, &pos);

	stack<int> s;
	for (int x = pos / 2; x > 0; x /= 2) {
		s.push(x);
	}
	
	if (s.size() >= k) return puts("-1"), 0;

	int idx = 1;
	while (!s.empty()) {
		tree[s.top()] = idx;
		idx++;
		s.pop();
	}

	queue<int> q;
	q.push(pos);
	idx = k;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		tree[x] = idx;
		idx++;

		if (2 * x <= n) q.push(2 * x);
		if (2 * x + 1 <= n) q.push(2 * x + 1);
	}

	if (idx - 1 > n) return puts("-1"), 0;

	vector<bool> used(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		if (tree[i]) used[tree[i]] = true;
	}
	vector<int> unused;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) unused.push_back(i);
	}

	for (int ui = 0, i = 1; i <= n; ++i) {
		if (!tree[i]) {
			tree[i] = unused[ui++];
		}
		printf("%d\n", tree[i]);
	}

	return 0;
}