#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e7;

vector<vector<int>> adj;

double dp[51][101];

int D, P;

// cur번 마을에서 교도소 P까지 D일 남았을 때, 갈 수 있는 확률
double solve(int cur, int d) {
	if (d == 0) return cur == P;

	double& ret = dp[cur][d];
	if (ret != -1) return ret;

	ret = 0;
	for (auto& next : adj[cur]) {
		// 내가 가려는 곳은 나를 1 / adj[next].size() 의 확률로 올 수 있기 때문
		ret += solve(next, d - 1) / (1e-12 + adj[next].size());
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		fill(&dp[0][0], &dp[50][100], -1.0);
		int n;
		scanf("%d %d %d", &n, &D, &P);
		adj = vector<vector<int>>(n);
		for (int i = 0; i < n; ++i) {
			adj.resize(n);
			for (int x, j = 0; j < n; ++j) {
				scanf("%d", &x);
				if (x) adj[i].push_back(j);
			}
		}

		// 거꾸로 구해보자. i에서 출발해서 교도소 P까지 몇 개의 경로로 갈 수 있을까?
		for (int i = 0; i < n; ++i) solve(i, D);

		int q;
		scanf("%d", &q);
		for (int x, i = 0; i < q; ++i) {
			scanf("%d", &x);
			printf("%.8lf ", dp[x][D]);
		}
		puts("");
	}
	return 0;
}