// 타잔 알고리즘

#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>2)

typedef pair<int, int> ii;

#define MAX_V 10000

int scc[MAX_V], visit[MAX_V];
stack<int> ready;

int dfs_count = 0;
vector<vector<int>> SCCs;

int tarjan(vector<int> adj[], int cur) {
	visit[cur] = dfs_count++;
	int president = visit[cur];
	ready.push(cur);
	for (auto& next : adj[cur]) {
		if (visit[next] == -1) {
			president = min(president, tarjan(adj, next));
		}
		else if (scc[next] == -1) {
			// not completed(finished) SCC yet.
			president = min(president, visit[next]);
		}
	}

	if (president == visit[cur]) {
		vector<int> component;
		while (!ready.empty()) {
			int top = ready.top();
			ready.pop();
			component.push_back(top);
			scc[top] = SCCs.size();
			if (cur == top) break;
		}
		SCCs.push_back(component);
	}

	return president;
}

vector<int> adj[MAX_V];
vector<int> adj_scc[MAX_V];

int main() {
	int V, E, start, end;
	scanf("%d %d %d %d", &V, &E, &start, &end);
	vector<ii> edges(E);
	for (int i = 0; i < E; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
		edges[i] = { u - 1, v - 1 };
	}

	memset(visit, -1, sizeof(visit));
	memset(scc, -1, sizeof(scc));
	for (int i = 0; i < V; ++i) {
		if (visit[i] == -1) {
			tarjan(adj, i);
		}
	}

	// SCC들 단위로 연결하는 간선
	for (auto& edge : edges) {
		int u = scc[edge.first], v = scc[edge.second];
		if(u != v) adj_scc[u].push_back(v);
	}

	// 중복되는 간선들을 제거
	for (auto& a : adj_scc) {
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
	}

	// 시작점 S가 속한 SCC와 끝점 T가 속한 SCC가 연결되어 있는 지?
	int startSCC = scc[start - 1], endSCC = scc[end - 1];
	vector<int> dist(SCCs.size(), 0);

	// BFS for Max Path on DAG
	queue<int> q;
	q.push(startSCC);
	dist[startSCC] = SCCs[startSCC].size();
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& next : adj_scc[cur]) {
			if (dist[next] < dist[cur] + (int)SCCs[next].size()) {
				dist[next] = dist[cur] + (int)SCCs[next].size();
				q.push(next);
			}
		}
	}

	printf("%d\n", dist[endSCC]);

	return 0;
}