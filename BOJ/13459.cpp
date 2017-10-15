#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,0,1,0 };
static int dy[] = { 0,-1,0,1 };

struct point {
	int y, x;
	bool operator < (const point& p) const {
		if (y == p.y) return x < p.x;
		return y < p.y;
	}
	bool operator == (const point& p) const {
		return y == p.y && x == p.x;
	}
};

char grid[10][11];
set<lld> visit;
int h, w;

bool inRange(int y, int x) {
	return 0 <= y && y < h && 0 <= x && x < w;
}

lld idx(point a, point b) {
	return (a.y * 10LL + a.x) * 100 + (b.y * 10LL + b.x);
}

void fetch(lld state, point *red, point *blue) {
	lld rs = state / 100, bs = state % 100;
	red->y = rs / 10, red->x = rs % 10;
	blue->y = bs / 10, blue->x = bs % 10;
}

bool isVisited(lld x) {
	return visit.find(x) != visit.end();
}

void chkVisit(lld x) {
	visit.insert(x);
}

point moveBall(point ball, point other, int d) {
	point res = ball;
	for (int y = ball.y, x = ball.x; inRange(y, x) && grid[y][x] != '#'; y += dy[d], x += dx[d]) {
		if (grid[y][x] == 'O') {
			res = { y, x };
			break;
		}
		if (y == other.y && x == other.x) break;
		res = { y, x };
	}
	return res;
}

lld nextState(lld state, int d) {
	point red, blue, fake = { -1,-1 };
	fetch(state, &red, &blue);
	if (red == blue) return state;
	if (d == 0 || d == 1) {
		if (red < blue) {
			red = moveBall(red, fake, d);
			blue = moveBall(blue, red, d);
		}
		else {
			blue = moveBall(blue, fake, d);
			red = moveBall(red, blue, d);
		}
	}
	else {
		if (red < blue) {
			blue = moveBall(blue, fake, d);
			red = moveBall(red, blue, d);
		}
		else {
			red = moveBall(red, fake, d);
			blue = moveBall(blue, red, d);
		}
	}
	return idx(red, blue);
}

int main() {
	scanf("%d %d", &h, &w);
	point red, blue, hole;
	for (int i = 0; i < h; ++i) {
		scanf("%s ", grid[i]);
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == 'R') red = { i, j }, grid[i][j] = '.';
			if (grid[i][j] == 'B') blue = { i, j }, grid[i][j] = '.';
			if (grid[i][j] == 'O') hole = { i, j };
		}
	}

	queue<lld> q;
	q.push(idx(red, blue));
	chkVisit(idx(red, blue));
	int dist = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			point r, b;
			lld curState = q.front();
			q.pop();
			fetch(curState, &r, &b);

			if (b == hole) continue;

			if (r == hole) {
				return puts("1"), 0;
			}

			for (int i = 0; i < 4; ++i) {
				lld next = nextState(curState, i);
				if (!isVisited(next)) {
					chkVisit(next);
					q.push(next);
				}
			}
		}
		if (++dist > 10) break;
	}
	puts("0");

	return 0;
}