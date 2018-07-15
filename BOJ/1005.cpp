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

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		vector<vector<ii>> adj(n);
		vector<int> t(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &t[i]);

		while (k--) {
			int s, e;
			scanf("%d %d", &s, &e);
			s--, e--;
			adj[e].push_back(ii(s, t[s]));
		}

		int goal;
		scanf("%d", &goal);

		goal--;
		vector<int> dist(n, 0);
		queue<ii> q;
		q.push(ii(goal, 0));

		while (!q.empty()) {
			int pos = q.front().first;
			int wei = q.front().second;
			q.pop();

			for (auto& next : adj[pos]) {
				int np = next.first, nw = next.second;
				if (dist[np] >= wei + nw) continue;
				dist[np] = wei + nw;
				q.push(ii(np, wei + nw));
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, dist[i] + t[goal]);
		}
		printf("%d\n", ans);
	}
	return 0;
}