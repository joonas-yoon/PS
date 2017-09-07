#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1,0,1,0 };
static int dx[] = { 0,1,0,-1 };

int h, w;
int a[51][51];

bool inRange(int y, int x) {
	return 0 <= y && y < h && 0 <= x && x < w;
}

int main(){
	int cy, cx, cd;
	scanf("%d %d %d %d %d", &h, &w, &cy, &cx, &cd);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			scanf("%d", &a[i][j]);

	a[cy][cx] = 2;

	while (true) {
		int ld = (cd + 3) % 4, nd = -1;
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (inRange(ny, nx) && a[ny][nx] == 0) {
				nd = i;
				break;
			}
		}
		if (nd == -1) {
			int py = cy - dy[cd], px = cx - dx[cd];
			if (!inRange(py, px) || a[py][px] == 1) break;
			cy = py, cx = px;
			continue;
		}

		int ly = cy + dy[ld], lx = cx + dx[ld];
		if (inRange(ly, lx) && a[ly][lx] == 0) {
			a[ly][lx] = 2;
			cy = ly, cx = lx, cd = ld;
			continue;
		}
		cd = ld;
	}

	int ans = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			ans += a[i][j] == 2;
	printf("%d\n", ans);

	return 0;
}