#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v;
	double w;
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

struct transceiver {
	int x, y;
};

double dist(transceiver& a, transceiver& b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	int Tcase;
	scanf("%d", &Tcase);
	while (Tcase--) {
		int s, n;
		scanf("%d %d", &s, &n);
		vector<int> group(n);
		vector<transceiver> T(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d ", &T[i].x, &T[i].y);
			group[i] = i;
		}

		vector<edge> E;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				E.push_back({ i, j, dist(T[i], T[j]) });
			}
		}
		sort(E.begin(), E.end());

		priority_queue<double> q;
		for (auto& e : E) {
			if (merge(group, e.u, e.v)) {
				q.push(e.w);
			}
		}

		// S-1개를 제거한다. (즉, S개를 위성기지로 지정한다)
		for (int i = 0; i < s - 1; ++i) q.pop();
		printf("%.2lf\n", q.top());
	}
	return 0;
}