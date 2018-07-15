#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using ii = pair<int, int>;

vector<ii> adj[32001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> indg(n, 0);
	vector<bool> leaf(n, true);
	while (m--) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		// (s, e)가 역간선임에 주의
		adj[s - 1].push_back(ii(e - 1, w));
		leaf[s - 1] = false;
		indg[e - 1]++;
	}

	// 완제품에 필요없는 부품은 모두 무시
	queue<int> q;
	vector<bool> visit(n, false);
	q.push(n - 1);
	visit[n - 1] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& next : adj[cur]) {
			int np = next.first;
			if (!visit[np]) {
				visit[np] = true;
				q.push(np);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			for (auto& x : adj[i])
				indg[x.first]--;
			adj[i].clear();
		}
	}

	// 완제품으로부터 역으로 BFS 진행
	vector<lld> result(n, 0);
	q.push(n - 1);
	result[n - 1] = 1;	// N번이 항상 완제품

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& next : adj[cur]) {
			int there = next.first;
			lld need = next.second;

			result[there] += need * result[cur];
			if(--indg[there] == 0)
				q.push(there);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (leaf[i] && result[i] > 0) {
			printf("%d %lld\n", i + 1, result[i]);
		}
	}

	return 0;
}