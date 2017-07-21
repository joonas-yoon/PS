#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

vector<ii> adj[10001];

vector<lld> solve(vector<bool>& market, int limit) {
	int V = market.size();
	vector<lld> Dist(V, LINF);
	priority_queue<ll> pq; /*(-dist, next)*/
	for (int i = 0; i < V; ++i) {
		if (market[i]) {
			pq.push({ 0, i });
			Dist[i] = 0;
		}
	}
	while (!pq.empty()) {
		lld curn = pq.top().second;
		lld curd = -pq.top().first;
		pq.pop();

		for (auto& next : adj[curn] /*(next, weight)*/ ) {
			lld nextn = next.first;
			lld nextd = curd + next.second;
			if (Dist[nextn] <= nextd || nextd > limit) continue;
			Dist[nextn] = nextd;
			pq.push({ -nextd, nextn });
		}
	}
	return Dist;
}

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	while (E--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back({ v - 1, w });
		adj[v - 1].push_back({ u - 1, w });
	}

	for (int i = 0; i < V; ++i) {
        sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	int macs, x;
	scanf("%d %d", &macs, &x);
	vector<bool> isMac(V, false);
	for (int k, i = 0; i < macs; ++i) {
		scanf("%d", &k);
		isMac[k - 1] = true;
	}
	vector<lld> MacDist = solve(isMac, x);

	int strs, y;
	scanf("%d %d", &strs, &y);
	vector<bool> isStr(V, false);
	for (int k, i = 0; i < strs; ++i) {
		scanf("%d", &k);
		isStr[k - 1] = true;
	}
	vector<lld> StrDist = solve(isStr, y);

	lld ans = LINF;
	for (int i = 0; i < V; ++i) {
		if (!isMac[i] && !isStr[i])
			ans = min(ans, MacDist[i] + StrDist[i]);
	}
	printf("%lld", ans < LINF ? ans : -1);

	return 0;
}