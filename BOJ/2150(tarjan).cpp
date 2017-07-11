// 타잔 알고리즘

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <set>
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
			scc[top] = SCCs.size() + 1;
			if (cur == top) break;
		}
		sort(component.begin(), component.end());
		SCCs.push_back(component);
	}

	return president;
}

int main() {
	int V, E;
	scanf("%d %d ", &V, &E);
	vector<int> adj[10001];
	for (int i = 0; i < E; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
	}

	memset(visit, -1, sizeof(visit));
	memset(scc, -1, sizeof(scc));
	for (int i = 0; i < V; ++i) {
		if (visit[i] == -1) {
			tarjan(adj, i);
		}
	}

	printf("%d\n", SCCs.size());
	sort(SCCs.begin(), SCCs.end());
	for (auto& scc : SCCs) {
		for (auto& v : scc) printf("%d ", v+1);
		puts("-1");
	}

	return 0;
}