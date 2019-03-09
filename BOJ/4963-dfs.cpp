#include <cstdio>
#include <cstring>

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int h, w;
int grid[51][51];
bool visit[51][51];

int dfs(int y, int x) {
	if (visit[y][x] || grid[y][x] == 0) return 0;

	visit[y][x] = true;
	for (int i = 0; i < 8; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		dfs(ny, nx);
	}
	return 1;
}

int main() {
	while (~scanf("%d %d", &w, &h) && h && w) {
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				scanf("%d", &grid[i][j]);
		}

		int count = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				count += dfs(i, j);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}