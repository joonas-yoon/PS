#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

static int dx[] = {1, 0, -1, 0};
static int dy[] = {0, 1, 0, -1};

deque<ii> snake;
bool v[101][101];
bool apple[101][101];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int x, y, i = 0; i < k; ++i) {
		scanf("%d %d", &y, &x);
		apple[y][x] = true;
	}

	int L, cy = 1, cx = 1, d = 0;
	snake.push_front(ii(cy, cx));
	v[cy][cx] = true;

	int ans = 0, t = 0;
	scanf("%d", &L);
	while (true) {
		int tm, dt;
		char c;
		if (L-- > 0) {
			scanf("%d %c ", &tm, &c);
			dt = tm - t;
			t = tm;
		} else {
			dt = n;
		}

		// dt초동안 이동
		while (dt--) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny < 1 || ny > n || nx < 1 || nx > n || v[ny][nx]) {
				return printf("%d\n", ans + 1), 0;
			}

			if (!apple[ny][nx]) {
				v[snake.back().first][snake.back().second] = false;
				snake.pop_back();
			}

			apple[ny][nx] = false;
			snake.push_front(ii(ny, nx));
			v[ny][nx] = true;

			cy = ny;
			cx = nx;
			++ans;
		}

		// dt초가 지나고 방향 전환
		if (c == 'L') {
			d = (d - 1 + 4) % 4;
		} else {
			d = (d + 1) % 4;
		}
	}

	return 0;
}