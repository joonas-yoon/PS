#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

int h, w;
int s[21][21];

ii bpos[4][3] = { // {dy, dx}
	{ {0, 0}, {0, 1}, {1, 0} }, // r
	{ {0, 0}, {0, 1}, {1, 1} }, // ㄱ
	{ {0, 0}, {1, 0}, {1, 1} }, // ㄴ
	{ {0, 0}, {1, 0}, {1, -1} } // ┘
};

bool inRange(int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; }

bool setBlock(int y, int x, int type, int val) {
	bool ret = true;
	for (int i = 0; i < 3; ++i) {
		int ny = y + bpos[type][i].first;
		int nx = x + bpos[type][i].second;
		if (!inRange(ny, nx)) {
			ret = false;
		}
		else if ((s[ny][nx] += val) > 1) {
			ret = false;
		}
	}
	return ret;
}

int solve() {
	int ny = -1, nx = -1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == 0) {
				ny = i, nx = j;
				break;
			}
		}
		if (ny != -1) break;
	}
	if (ny == -1) return 1;

	int ret = 0;
	for (int t = 0; t < 4; ++t) {
		if (setBlock(ny, nx, t, 1)) {
			ret += solve();
		}
		setBlock(ny, nx, t, -1);
	}
	return ret;
}

int main() {
	int T;
	scanf("%d ", &T);
	while (T--) {
		memset(s, 0, sizeof(s));
		scanf("%d %d ", &h, &w);
		for (int i = 0; i < h; ++i) {
			char p[21] = {};
			scanf("%s ", p);
			for (int j = 0; j < w; ++j) s[i][j] = p[j] == '#';
		}
		printf("%d\n", solve());
	}
	return 0;
}