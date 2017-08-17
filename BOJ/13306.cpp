#include <bits/stdc++.h>
using namespace std;

int group[200005];

int find(int p) {
	if (p == group[p]) return p;
	return group[p] = find(group[p]);
}

void merge(int p, int q) { // p <- q
	group[find(q)] = find(p);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> parent(n + 1, 0);
	for (int i = 1; i <= n; ++i) group[i] = i;
	for (int u, i = 2; i <= n; ++i) {
		scanf("%d", &u);
		parent[i] = u;
	}

	vector<vector<int>> query(n - 1 + q);
	for (int x, a, b, i = 0; i < n - 1 + q; ++i) {
		scanf("%d %d", &x, &a);
		if (x) {
			scanf("%d", &b);
			query[i] = { x, a, b };
		}
		else {
			query[i] = { x, a };
		}
	}

	// 쿼리에서 끊는 것이 없는건 처음부터 붙어있도록 한다.
	vector<bool> hasEdge(n + 1, true);
	for (auto& q : query) {
		if (q.size() == 2) hasEdge[q[1]] = false;
	}
	for (int i = 1, first = 0; i <= n; ++i) {
		if (hasEdge[i]) {
			if (!first) first = i;
			merge(first, i);
		}
	}

	vector<string> ans;
	for (int i = (int)query.size() - 1; i >= 0; --i) {
		if (query[i][0]) {
			if (find(query[i][1]) == find(query[i][2])) ans.push_back("YES");
			else ans.push_back("NO");
		}
		else {
			int node = query[i][1];
			merge(node, parent[node]);
		}
	}

	for (int i = (int)ans.size() - 1; i >= 0; --i) puts(ans[i].c_str());

	return 0;
}