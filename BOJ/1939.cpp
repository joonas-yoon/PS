#include <bits/stdc++.h>
using namespace std;

struct edge {
	int s, e, cost;
	bool operator < (const edge& o) {
		return cost < o.cost;
	}
};

int n;
vector<edge> edges;

int group[10001];

int find(int p) {
	if (group[p] == p) return p;
	return group[p] = find(group[p]);
}

void merge(int p, int q) {
	// merge p into q
	p = find(p);
	q = find(q);
	group[p] = q;
}

// 연결되는 간선 중 최대값
int maximumCost(int s, int e) {
	for (int i = 0; i < n; ++i) group[i] = i;
	
	std::sort(edges.rbegin(), edges.rend());
	for (int i = 0; i < edges.size(); ++i) {
		merge(edges[i].s, edges[i].e);
        
        if (find(s) == find(e)) {
			return edges[i].cost;
		}
	}
	return 0;
}

int main() {
	int m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({a - 1, b - 1, c});
	}

	int start, end;
	scanf("%d %d", &start, &end);
	printf("%d\n", maximumCost(start-1, end-1));

	return 0;
}