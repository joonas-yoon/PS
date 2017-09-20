#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

#define MAX_V 10001

int scc[MAX_V], visit[MAX_V];
int sccSize[MAX_V];
stack<int> ready;

int dfs_count = 0, scc_count = 0;

vector<int> adj[MAX_V];
vector<int> sadj[MAX_V];

int tarjan(int cur) {
	visit[cur] = dfs_count++;
	int president = visit[cur];
	ready.push(cur);
	for (auto& next : adj[cur]) {
		if (visit[next] == -1)
			president = min(president, tarjan(next));
		else if (scc[next] == -1) {
			// not completed(finished) SCC yet.
			president = min(president, visit[next]);
		}
	}

	if (president == visit[cur]) {
		while (!ready.empty()) {
			int top = ready.top();
			ready.pop();
			scc[top] = scc_count;
			sccSize[scc[top]] += 1;
			if (cur == top) break;
		}
		scc_count += 1;
	}
	return president;
}

bool vis[MAX_V];
int dfs(int cur) {
	vis[cur] = true;
	int ret = sccSize[cur];
	for (auto& next : sadj[cur]) {
		if (!vis[next]) {
			ret += dfs(next);
		}
	}
	return ret;
}

int main() {
	int V, E;
	scanf("%d %d ", &V, &E);
	for (int u, v, i = 0; i < E; ++i) {
		scanf("%d %d", &v, &u);
		adj[u - 1].push_back(v - 1);
	}

	memset(visit, -1, sizeof(visit));
	memset(scc, -1, sizeof(scc));
	for (int i = 0; i < V; ++i)
		if (visit[i] == -1)
			tarjan(i);

	for (int i = 0; i < V; ++i) {
		for (auto next : adj[i]) {
			if (scc[next] == scc[i]) continue;
			sadj[scc[i]].push_back(scc[next]);
		}
	}

	for (int i = 0; i < scc_count; ++i) {
		sort(sadj[i].begin(), sadj[i].end());
		sadj[i].erase(unique(sadj[i].begin(), sadj[i].end()), sadj[i].end());
	}

	int maxD = 0;
	vector<int> answer(scc_count, 0);
	for (int i = 0; i < scc_count; ++i) {
		memset(vis, false, sizeof(vis));
		answer[i] = dfs(i);
		maxD = max(maxD, answer[i]);
	}

	for (int i = 0; i < V; ++i) {
		if (maxD == answer[scc[i]]) printf("%d ", i + 1);
	}

	return 0;
}