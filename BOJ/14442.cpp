#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

// [i][j] 까지 [k]개를 부쉈을 때, 최단 거리
int d[1001][1001][11];
char a[1001][1001];

struct cell {
	int y, x, k;
};

int main() {
	memset(d, -1, sizeof(d));
	int h, w, k;
	scanf("%d %d %d", &h, &w, &k);
	for (int i = 0; i < h; ++i) scanf("%s ", a[i]);

	queue<cell> q;
	int dist = 1;
	bool find = false;
	q.push({ 0, 0, 0 });
	d[0][0][0] = 1;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			cell cur = q.front();
			q.pop();

			if (cur.y == h - 1 && cur.x == w - 1) {
				return !printf("%d\n", dist);
			}

			for (int i = 0; i < 4; ++i) {
				int ny = cur.y + dy[i], nx = cur.x + dx[i];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				int nk = cur.k + (a[ny][nx] == '1');
				if (nk > k) continue;
				int& next = d[ny][nx][nk];
				if (next == -1 || next > dist + 1) {
					next = dist + 1;
					q.push({ ny, nx, nk });
				}
			}
		}
		if (find) break;
		++dist;
	}
	if (find) printf("%d\n", dist);
	else puts("-1");
	return 0;
}