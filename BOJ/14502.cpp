#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

static int dy[] = { -1,0,1,0 };
static int dx[] = { 0,1,0,-1 };

int h, w;
int grid[8][8];
vector<ii> spot, virus;
bool stats[8][8];

void dfs(int y, int x) {
	if (stats[y][x]) return;
	stats[y][x] = true;
	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d], nx = x + dx[d];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (stats[ny][nx] || grid[ny][nx] != 0) continue;
		dfs(ny, nx);
	}
}

int solve(vector<ii> block) {
	for (auto& b : block)
		grid[b.first][b.second] = 1;

	memset(stats, false, sizeof(stats));

	for(auto& v : virus) dfs(v.first, v.second);

	int ret = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			ret += grid[i][j] == 0 && stats[i][j] == 0;
		}
	}

	for (auto& b : block)
		grid[b.first][b.second] = 0;
	return ret;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 0) spot.push_back({ i, j });
			if (grid[i][j] == 2) virus.push_back({ i, j });
		}
	}

	int n = spot.size(), ans = 0;
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				ans = max(ans, solve({ spot[i], spot[j], spot[k] }));
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}