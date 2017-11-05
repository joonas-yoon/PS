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

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

vector<int> grp[405];
int capacity[405][405];
int flow[405][405];

int nodes;

int bfs(int src, int sink) {
	vector<int> from(nodes, -1);
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == sink) break;

		for (auto& next : grp[cur]) {
			if (capacity[cur][next] - flow[cur][next] > 0 && from[next] == -1) {
				q.push(next);
				from[next] = cur;
			}
		}
	}

	if (from[sink] == -1) return 0;
   
    int f = 1;
	for (int i = sink; i != src; i = from[i]) f = min(f, capacity[from[i]][i] - flow[from[i]][i]);
	for (int i = sink; i != src; i = from[i]) {
		flow[from[i]][i] += f;
		flow[i][from[i]] -= f;
	}
	return f;
}

int main() {
	int cows, barns;
	scanf("%d %d", &cows, &barns);
	nodes = cows + barns + 1 /* sink */;
	int sink = nodes - 1;
	for (int k, i = 0; i < cows; ++i) {
		scanf("%d", &k);
		for (int v, j = 0; j < k; ++j) {
			scanf("%d ", &v);
			grp[i].push_back(cows + v - 1);
			grp[cows + v - 1].push_back(i);
			capacity[i][cows + v - 1] = 1;
		}
	}
	for (int i = 0; i < barns; ++i) {
		grp[cows + i].push_back(sink);
		capacity[cows + i][sink] = 1;
	}

	int ans = 0;
	for (int i = 0; i < cows; ++i) {
		ans += bfs(i, sink);
	}
	printf("%d\n", ans);
	return 0;
}