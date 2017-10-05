#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

struct sb {
	int x, t;
	bool operator < (const sb& p) const {
		return t > p.t;
	}
};

vector<int> dist;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int bound = max(1, max(n, k)) * 2;
	dist = vector<int>(bound, INF);

	priority_queue<sb> q;
	q.push({ n, 0 });
	dist[n] = 0;
	while (!q.empty()) {
		sb cur = q.top();
		q.pop();

		int x = cur.x, ct = cur.t;

		if (x == k) return printf("%d\n", ct), 0;

		int ndx[] = { x - 1, x + 1, 2 * x };
		for (int i = 0; i < 3; ++i) {
			int nx = ndx[i], nc = ct + (i != 2);
			if (nx < 0 || nx >= bound || nc >= dist[nx]) continue;
			dist[nx] = nc;
			q.push({ nx, nc });
		}
	}

	return 0;
}