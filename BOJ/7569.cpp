#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int m, n, h;
int a[101][101][101];

struct pt {
	int x, y, z;
};

bool solved() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k)
				if (a[i][j][k] == 0) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d %d %d", &m, &n, &h);
	queue<pt> q;
	for (int z = 0; z < h; ++z) {
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < m; ++x) {
				scanf("%d", &a[z][y][x]);
				if (a[z][y][x] == 1) {
					q.push({ x, y, z });
				}
			}
		}
	}

	int day = 0;
	while (!q.empty()) {
		int qs = q.size();
		bool find = false;
		while (qs--) {
			pt cur = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int ny = cur.y + dy[i], nx = cur.x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[cur.z][ny][nx] != 0) continue;
				a[cur.z][ny][nx] = 1;
				q.push({ nx, ny, cur.z });
				find = true;
			}
			int dz[] = { -1, 1 };
			for (int i = 0; i < 2; ++i) {
				int nz = cur.z + dz[i];
				if (nz < 0 || nz >= h || a[nz][cur.y][cur.x] != 0) continue;
				a[nz][cur.y][cur.x] = 1;
				q.push({ cur.x, cur.y, nz });
				find = true;
			}
		}
		if (!find) break;
		++day;
	}

	if (!solved()) puts("-1");
	else printf("%d\n", day);

	return 0;
}