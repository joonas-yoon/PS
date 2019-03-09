#include <cstdio>
#include <cstring>
#include <algorithm> // std::max
using namespace std;

static int dx[] = {-1,1,0,0};
static int dy[] = {0,0,-1,1};

int h, w;
int grid[501][501];
bool visit[501][501];

int dfs(int y, int x) {
	if (visit[y][x] || grid[y][x] == 0) return 0;

	visit[y][x] = true;

	int area = 1; // count this
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

		area += dfs(ny, nx);
	}

	return area;
}

int main() {
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			scanf("%d", &grid[i][j]);
	}

	int count = 0, maxArea = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int area = dfs(i, j);
			if (area > 0) {
				count++;
				maxArea = max(maxArea, area);
			}
		}
	}
	printf("%d\n%d\n", count, maxArea);

	return 0;
}