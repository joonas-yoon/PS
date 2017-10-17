#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w;
	bool operator < (const edge& p) const { return w < p.w; }
};

int find(vector<int>& r, int k) {
	if (k == r[k]) return k;
	return r[k] = find(r, r[k]);
}

bool merge(vector<int>& root, int p, int q) {
	p = find(root, p);
	q = find(root, q);
	if (p == q) return false;
	root[q] = p;
	return true;
}

int kruskal(edge E[], int vertex, int edges) {
	vector<int> ds(vertex + 1);
	for (int i = 0; i <= vertex; ++i) ds[i] = i;
	sort(E, E + edges);
	int ans = 0;
	for (int i = 0; i < edges; ++i)
		if (merge(ds, E[i].u, E[i].v))
			ans += E[i].w;
	return ans;
}

edge E[100001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		E[i] = { u - 1, v - 1, w };
	}
	printf("%d\n", kruskal(E, n, m));
	return 0;
}