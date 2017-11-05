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
    bool find = false;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& next : grp[cur]) {
			if (capacity[cur][next] - flow[cur][next] > 0 && from[next] == -1) {
				q.push(next);
				from[next] = cur;
                if (next == sink){
                    find = true;
                    break;
                }
			}
		}
        
        if (find) break;
	}

	if (from[sink] == -1) return 0;

    int f = INF;
    for (int i = sink; i != src; i = from[i])
        f = min(f, capacity[from[i]][i] - flow[from[i]][i]);
	for (int i = sink; i != src; i = from[i]) {
		flow[from[i]][i] += f;
		flow[i][from[i]] -= f;
	}
	return f;
}

int get_max_flow(int src, int sink){
    int ans = 0;
    while (true) {
        int f = bfs(src, sink);
        if (!f) break;
        ans += f;
    }
    return ans;
}

int main() {
	int mans, works;
	scanf("%d %d", &mans, &works);
	int nodes = mans + works + 2;
	int src = 0, sink = nodes - 1;
	for (int k, v, i = 1; i <= mans; ++i) {
        grp[src].push_back(i);
        grp[i].push_back(src);
        capacity[src][i] = 2;
        
		scanf("%d", &k);
        while (k--) {
			scanf("%d ", &v);
			grp[i].push_back(mans + v);
			grp[mans + v].push_back(i);
			capacity[i][mans + v] = 1;
		}
	}
	for (int i = 1; i <= works; ++i) {
		grp[mans + i].push_back(sink);
		grp[sink].push_back(mans + i);
		capacity[mans + i][sink] = 1;
	}

	printf("%d\n", get_max_flow(src, sink));
	return 0;
}