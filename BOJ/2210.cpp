#include <cstdio>

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

int a[5][5];
bool v[999999 + 2];

int solve(int y, int x, int dep, int num) {
	if (y < 0 || y >= 5 || x < 0 || x >= 5) return 0;
	if (dep > 5) {
		if (v[num]) return false;
		return v[num] = true;
	}
	int cnt = 0;
	for (int d = 0; d < 4; ++d) {
		cnt += solve(y + dy[d], x + dx[d], dep + 1, 10 * num + a[y][x]);
	}
	return cnt;
}

int main() {
	for (int i = 0; i < 25; ++i) scanf("%d", &a[i / 5][i % 5]);
	int r = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			r += solve(i, j, 0, 0);
		}
	}
	printf("%d\n", r);
	return 0;
}