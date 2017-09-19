#include <cstdio>

static int dy[] = { -1,-1,-1,0,0,1,1,1 };
static int dx[] = { -1,0,1,-1,1,-1,0,1 };

int h, w;
int a[255][255];
bool v[255][255];

bool solve(int i, int j) {
	v[i][j] = true;
	for (int d = 0; d < 8; ++d) {
		int ny = i + dy[d], nx = j + dx[d];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w || !a[ny][nx] || v[ny][nx]) continue;
		solve(ny, nx);
	}
	return true;
}

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			scanf("%d", &a[i][j]);

	int ans = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (a[i][j] && !v[i][j]) ans += solve(i, j);
	printf("%d\n", ans);

	return 0;
}