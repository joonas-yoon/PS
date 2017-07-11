// 코사라주 알고리즘 for SCC

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

bool visit[10001];
stack<int> points;

void pre_dfs(vector<int> adj[], int cur) {
	if (visit[cur]) return;
	visit[cur] = true;
	for (auto& next : adj[cur]) {
		pre_dfs(adj, next);
	}
	points.push(cur);
}

void dfs(vector<int> adj[], int cur, vector<int>& ret) {
	if (visit[cur]) return;
	visit[cur] = true;
	ret.push_back(cur+1);
	for (auto& next : adj[cur]) {
		dfs(adj, next, ret);
	}
}

int main() {
	int V, E;
	scanf("%d %d ", &V, &E);
	vector<int> adj[10001], rev[10001];
	for (int i = 0; i < E; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
		rev[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < V; ++i) {
		pre_dfs(adj, i);
	}

	memset(visit, false, sizeof(visit));
	vector<vector<int>> SCCs;
	while(!points.empty()){
		vector<int> scc;
		dfs(rev, points.top(), scc);
		points.pop();
		if (!scc.empty()) {
			sort(scc.begin(), scc.end());
			SCCs.push_back(scc);
		}
	}

	sort(SCCs.begin(), SCCs.end());
	printf("%d\n", SCCs.size());
	for (auto& scc : SCCs) {
		for (auto& v : scc) printf("%d ", v);
		puts("-1");
	}

	return 0;
}