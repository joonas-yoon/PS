#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> indg(n + 1, 0);
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		indg[e]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= n; ++i) {
		if (indg[i] == 0)
			pq.push(-i);
	}

	while (!pq.empty()) {
		int cur = -pq.top();
		pq.pop();

		printf("%d ", cur);

		for (auto& next : adj[cur]) {
			if (--indg[next] == 0)
				pq.push(-next);
		}
	}

	return 0;
}