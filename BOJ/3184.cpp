#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int h, w;
char a[255][255];

struct sw {
	int sheep, wolf;
	sw operator += (const sw& s) {
		sheep += s.sheep;
		wolf += s.wolf;
		return *this;
	}
};

sw dfs(int y, int x) {
	sw cur = { a[y][x] == 'o', a[y][x] == 'v' };
	a[y][x] = '#'; // visit
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w || a[ny][nx] == '#') continue;
		cur += dfs(ny, nx);
	}
	return cur;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) scanf("%s ", a[i]);
	int sheep = 0, wolf = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (a[i][j] != '#') {
				sw res = dfs(i, j);
				if (res.sheep > res.wolf) {
					sheep += res.sheep;
				}
				else {
					wolf += res.wolf;
				}
			}
		}
	}
	printf("%d %d\n", sheep, wolf);
	return 0;
}