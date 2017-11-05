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

vector<int> grp[2002];
int capacity[2002][2002];
int flow[2002][2002];
int from[2002];

int bfs(int src, int sink) {
    memset(from, -1, sizeof(from));
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

	for (int i = sink; i != src; i = from[i]) {
		flow[from[i]][i] += 1;
		flow[i][from[i]] -= 1;
	}
	return 1;
}

int main() {
	int mans, works;
	scanf("%d %d", &mans, &works);
	int nodes = mans + works + 1;
	int sink = nodes - 1;
	for (int k, i = 0; i < mans; ++i) {
		scanf("%d", &k);
		for (int v, j = 0; j < k; ++j) {
			scanf("%d ", &v);
			grp[i].push_back(mans + v - 1);
			grp[mans + v - 1].push_back(i);
			capacity[i][mans + v - 1] = 1;
		}
	}
	for (int i = 0; i < works; ++i) {
		grp[mans + i].push_back(sink);
		grp[sink].push_back(mans + i);
		capacity[mans + i][sink] = 1;
	}

	int ans = 0;
	for (int i = 0; i < mans; ++i) {
		ans += bfs(i, sink);
	}
	printf("%d\n", ans);
	return 0;
}