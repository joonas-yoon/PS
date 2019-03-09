#include <cstdio>
#include <cstring> // memset
#include <vector>
#include <queue>
#include <algorithm> // sort
using namespace std;

int n;
vector<int> adj[1001];
bool visit[1001];

void dfs(int cur) {
	if (visit[cur]) return;

	visit[cur] = true;
	printf("%d ", cur);
	for (int i = 0; i < adj[cur].size(); ++i) {
		int next = adj[cur][i];
		dfs(next);
	}
}

void bfs(int start) {
	memset(visit, false, sizeof(visit));

	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		printf("%d ", cur);

		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; ++i) {
		int start, end;
		scanf("%d %d", &start, &end);
		// 양방향 간선
		adj[start].push_back(end);
		adj[end].push_back(start);
	}

	// 정점 번호가 작은 것을 먼저 방문
	for (int i = 0; i < n; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(v);
	puts("");

	bfs(v);

	return 0;
}