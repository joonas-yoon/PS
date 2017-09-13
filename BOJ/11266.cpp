#include <bits/stdc++.h>
using namespace std;

int dis_id;
vector<int> discover;
vector<bool> isArticul;
vector<vector<int>> adj;

int dfs(int cur, bool isRoot = true) {
	discover[cur] = ++dis_id;
	int ret = discover[cur];

	int child = 0;
	for (auto& next : adj[cur]) {
		if (discover[next] == 0) {
			child++;
			int low = dfs(next, false);
			if (!isRoot && low >= discover[cur]) {
				isArticul[cur] = true;
			}
			ret = min(ret, low);
		}
		else {
			ret = min(ret, discover[next]);
		}
	}

	if (isRoot) {
		isArticul[cur] = child > 1;
	}
	return ret;
}

int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	adj.resize(v + 1);
	discover = vector<int>(v + 1, 0);
	isArticul = vector<bool>(v + 1, false);
	while (e--) {
		int f, s;
		scanf("%d %d", &f, &s);
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	for (int i = 1; i <= v; ++i) {
		if (!discover[i]) dfs(i);
	}

	vector<int> ans;
	for (int i = 1; i <= v; ++i) {
		if (isArticul[i]) ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (auto& x : ans) printf("%d ", x);

	return 0;
}