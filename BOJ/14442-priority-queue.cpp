#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

// [i][j] 까지 [k]개를 부쉈을 때, 최단 거리
int dist[1001][1001][11];
char a[1001][1001];

struct cell {
	int y, x, k, d;
	bool operator < (const cell& c) const {
		if (d == c.d) return k > c.k;
		return d > c.d;
	}
};

int main() {
	memset(dist, -1, sizeof(dist));
	int h, w, k;
	scanf("%d %d %d", &h, &w, &k);
	for (int i = 0; i < h; ++i) scanf("%s ", a[i]);

	priority_queue<cell> pq;
	pq.push({ 0, 0, 0, 1 });
	while (!pq.empty()) {
		cell cur = pq.top();
		pq.pop();

		if (cur.y == h - 1 && cur.x == w - 1) {
			return !printf("%d\n", cur.d);
		}

		for (int i = 0; i < 4; ++i) {
			int ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			int nk = cur.k + (a[ny][nx] == '1');
			if (nk > k) continue;
			int& next = dist[ny][nx][nk];
			if (next == -1 || next > cur.d + 1) {
				next = cur.d + 1;
				pq.push({ ny, nx, nk, cur.d + 1 });
			}
		}
	}
	puts("-1");
	return 0;
}