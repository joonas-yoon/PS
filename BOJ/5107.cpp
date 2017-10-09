#include <bits/stdc++.h>
using namespace std;

int group[55];

int dfs(vector<int> adj[], int cur, int color) {
	if (group[cur]) return group[cur];
	group[cur] = color;
	for (auto& next : adj[cur]) {
		group[cur] = dfs(adj, next, color);
	}
	return group[cur];
}

map<string, int> names;
int getNameIndex(string s) {
    int sz = names.size();
	if (names.find(s) == names.end()) names[s] = sz;
	return names[s];
}

int main() {
	int n, tc = 0;
	while (~scanf("%d ", &n) && n) {
		vector<int> adj[55];
		names.clear();
		for (int i = 0; i < n; ++i) {
			char n1[1024], n2[1024];
			scanf("%s %s ", &n1, &n2);
			int u = getNameIndex(n1), v = getNameIndex(n2);
			adj[u].push_back(v);
		}

		int V = names.size(), ans = 0;
		memset(group, 0, sizeof(group));
		int color = 1;
		for (int i = 0; i < V; ++i) {
			color = dfs(adj, i, color) + 1;
		}
		printf("%d %d\n", ++tc, color - 1);
	}
	return 0;
}