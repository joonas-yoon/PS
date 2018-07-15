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

		vector<vector<int>> adj(n);
		vector<int> t(n), res(n, 0);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &t[i]);
			res[i] = t[i];
		}

		vector<int> indegree(n, 0);
		while (k--) {
			int s, e;
			scanf("%d %d", &s, &e);
			adj[s - 1].push_back(e - 1);
			indegree[e - 1]++;
		}

		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (indegree[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			
			for (auto& next : adj[cur]) {
				res[next] = max(res[next], res[cur] + t[next]);
				if (--indegree[next] == 0) {
					q.push(next);
				}
			}
		}

		int goal;
		scanf("%d", &goal);
		printf("%d\n", res[goal - 1]);
	}
	return 0;
}