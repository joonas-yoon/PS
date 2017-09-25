#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int h, w;
bool v[301][301];
int  a[301][301];

bool dfs(int y, int x) {
	if (y < 0 || y >= h || x < 0 || x >= w || a[y][x] <= 0 || v[y][x]) return false;
	v[y][x] = true;
	for (int i = 0; i < 4; ++i) dfs(y + dy[i], x + dx[i]);
	return true;
}

int main() {
	int pa[301][301];
	scanf("%d %d", &h, &w);
	bool hasOne = false;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			scanf("%d ", &a[i][j]), hasOne |= a[i][j] != 0;

	int t = 0, ans = 0;
	while(hasOne){
		memset(v, false, sizeof(v));
		int groups = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				groups += dfs(i, j);
			}
		}
		if (!groups) break;

		if (groups >= 2) {
			ans = t;
			break;
		}

		++t;
		memcpy(pa, a, sizeof(a));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				int cnt = 0;
				for (int d = 0; d < 4; ++d) {
					int ny = i + dy[d], nx = j + dx[d];
					if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
					cnt += pa[ny][nx] <= 0;
				}
				a[i][j] -= cnt;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}