#include <bits/stdc++.h>
using namespace std;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

int h, w, n;
int	grid[110][110];
struct robot {
	int y, x, d;
};
vector<robot> robots;

int direction(char c) {
	for (int i = 0; i < 4; ++i)
		if ("WSEN"[i] == c) return i;
	return -1;
}

char fr;

int main() {
	int m;
	scanf("%d %d %d %d", &w, &h, &n, &m);
	for (int y, x, i = 0; i < n; ++i) {
		scanf("%d %d %c ", &x, &y, &fr);
		grid[y][x] = i + 1;
		robots.push_back({ y, x, direction(fr) });
	}
	while (m--) {
		int id, lp;
		scanf("%d %c %d ", &id, &fr, &lp);
		robot& r = robots[id - 1];
		if (fr == 'L' || fr == 'R') {
			lp %= 4;
			for (int i = 0; i < lp; ++i)
				r.d = (r.d + (fr == 'R' ? 3 : 1)) % 4;
		}
		else {
			for (int i = 0; i < lp; ++i) {
				grid[r.y][r.x] = 0;
				int ny = r.y + dy[r.d], nx = r.x + dx[r.d];
				if (ny < 1 || ny > h || nx < 1 || nx > w)
					return !printf("Robot %d crashes into the wall\n", id);
				if(grid[ny][nx] && grid[ny][nx] != id)
					return !printf("Robot %d crashes into robot %d\n", id, grid[ny][nx]);
				r.y = ny, r.x = nx;
				grid[r.y][r.x] = id;
			}
		}
	}
	puts("OK");
	return 0;
}