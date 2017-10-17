#include <bits/stdc++.h>
using namespace std;

using lld = long long;

struct edge {
	int u, v, w;
	bool operator < (const edge& e) const {
		return w < e.w;
	}
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

struct planet {
	int id, x, y, z;
	int dist(const planet& p) {
		return min({ abs(x - p.x), abs(y - p.y), abs(z - p.z) });
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<int> group(n);
	vector<planet> T(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &T[i].x, &T[i].y, &T[i].z);
		T[i].id = i;
		group[i] = i;
	}

	vector<edge> E;
	sort(T.begin(), T.end(), [](planet& a, planet& b) -> bool { return a.x < b.x; });
	for (int i = 1; i < n; ++i) E.push_back({ T[i - 1].id, T[i].id, T[i - 1].dist(T[i]) });
	sort(T.begin(), T.end(), [](planet& a, planet& b) -> bool { return a.y < b.y; });
	for (int i = 1; i < n; ++i) E.push_back({ T[i - 1].id, T[i].id, T[i - 1].dist(T[i]) });
	sort(T.begin(), T.end(), [](planet& a, planet& b) -> bool { return a.z < b.z; });
	for (int i = 1; i < n; ++i) E.push_back({ T[i - 1].id, T[i].id, T[i - 1].dist(T[i]) });

	sort(E.begin(), E.end());
	lld ans = 0;
	for (auto& e : E) {
		if (merge(group, e.u, e.v))
			ans += e.w;
	}
	printf("%lld\n", ans);
	return 0;
}