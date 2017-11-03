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

map<string, int> nodes;

int getId(string s) {
	int sz = nodes.size();
	if (nodes.find(s) == nodes.end()) nodes[s] = sz;
	return nodes[s];
}

int capacity[1400][1400];
bool visit[1400];

int dfs(int cur, int sink, int flow) {
	if (visit[cur]) return 0;
	visit[cur] = true;

	if (cur == sink) return flow;

	for (int there = 0; there < nodes.size(); ++there) {
		// residual path
		if (capacity[cur][there] > 0) {
			int f = dfs(there, sink, min(flow, capacity[cur][there]));
			if (f > 0) {
				capacity[cur][there] -= f;
				capacity[there][cur] += f;
				return f;
			}
		}
	}
	return 0;
}

int get_flow(int source, int sink) {
	int ans = 0, f = -1;
	while (f) {
		memset(visit, false, sizeof(visit));
		f = dfs(source, sink, INF);
		ans += f;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d ", &n);
	for (int f, i = 0; i < n; ++i) {
		char u[101], v[101];
		scanf("%s %s %d ", &u, &v, &f);
		int ui = getId(u), vi = getId(v);
		capacity[ui][vi] += f;
		capacity[vi][ui] += f;
	}

	int src = getId("A"), sink = getId("Z");
	printf("%d\n", get_flow(src, sink));

	return 0;
}