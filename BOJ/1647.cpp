#include <bits/stdc++.h>
using namespace std;

using lld = long long;

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

lld solve(vector<edge>& E, int vertex) {
	vector<int> ds(vertex + 1);
	for (int i = 0; i <= vertex; ++i) ds[i] = i;
	sort(E.begin(), E.end());
	lld ans = 0, largest = 0;
	for (auto& e : E) {
		if (merge(ds, e.u, e.v)) {
			ans += e.w;
			largest = max(largest, 0LL + e.w);
		}
	}
	return ans - largest;
}

vector<edge> E;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	E.resize(m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		E[i] = { u - 1, v - 1, w };
	}
	printf("%lld\n", solve(E, n));
	return 0;
}