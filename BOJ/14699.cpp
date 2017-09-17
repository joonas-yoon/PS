#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> adj[5001];
int height[5001];
int dp[5001];

int solve(int cur) {
	int& ret = dp[cur];
	if (ret != -1) return ret;
	ret = 1;
	for (auto& next : adj[cur]) {
		ret = max(ret, 1 + solve(next.second));
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &height[i]);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (height[u] < height[v]) adj[u].push_back({ height[v], v });
		if (height[u] > height[v]) adj[v].push_back({ height[u], u });
	}

	for (int i = 1; i <= n; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", solve(i));
	}
	return 0;
}