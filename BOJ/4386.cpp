#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v;
	double w;
	bool operator < (const edge& p) const { return w < p.w; }
};

struct star {
	double x, y;
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


int main() {
	int n;
	scanf("%d", &n);
	vector<star> S(n);
	vector<int> group(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf ", &S[i].x, &S[i].y);
		group[i] = i;
	}

	vector<edge> E;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			double dx = S[i].x - S[j].x, dy = S[i].y - S[j].y;
			E.push_back({ i, j, dx*dx + dy*dy });
		}
	}

	sort(E.begin(), E.end());
	double ans = 0;
	for (auto& e : E) {
		if (merge(group, e.u, e.v)) {
			ans += sqrt(e.w);
		}
	}
	printf("%.2lf\n", ans + 1e-12);

	return 0;
}