#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

static int dy[] = {-1,0,1,0};
static int dx[] = {0,1,0,-1};

char grid[101][101];
char danger[101][101];

struct node {
	int y, x, dir;
};

bool getBit(char x, int d) {
	return x & (1<<d);
}

void setBit(char& x, int d) {
	x |= (1 << d);
}

int main() {
	int h, w;
	scanf("%d %d ", &h, &w);

	queue<node> q;
	for (int i = 0; i < h; ++i) {
		scanf("%s ", grid[i]);
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == 'W') {
				q.push({i, j, -1});
				danger[i][j] = (1 << 4) - 1;
			}
		}
	}

	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cy = q.front().y;
			int cx = q.front().x;
			int cd = q.front().dir;
			q.pop();

			// 빙판길은 방향이 결정되어있음
			if (cd != -1) {
				int d = cd;
				int ny = cy + dy[d];
				int nx = cx + dx[d];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

				char& ch = grid[ny][nx];
				if (!getBit(danger[ny][nx], d) && ch != '#') {
					q.push({ny, nx, ch == '+' ? d : -1});
					setBit(danger[ny][nx], d);
					continue;
				} else if (ch != '#') {
                    // 빙판이더라도 앞이 벽이면 4방향 탐색을 해야함
					continue;
				}
			}

			for (int d = 0; d < 4; ++d) {
				int ny = cy + dy[d];
				int nx = cx + dx[d];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

				char& ch = grid[ny][nx];
				if (getBit(danger[ny][nx], d) || ch == '#') continue;
				q.push({ny, nx, ch == '+' ? d : -1});
				setBit(danger[ny][nx], d);
			}
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == '.')
				putchar(danger[i][j] ? '.' : 'P');
			else
				putchar(grid[i][j]);
		}
		puts("");
	}

	return 0;
}