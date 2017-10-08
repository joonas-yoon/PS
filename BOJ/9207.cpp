#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dx[] = { -1,1,0,0 };
static int dy[] = { 0,0,-1,1 };

struct point {
	int y, x;
};

ii solve(vector<string> s) {
	vector<point> v;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (s[i][j] == 'o') {
				v.push_back({ i, j });
			}
		}
	}

	ii ret = make_pair(v.size(), 0);
	for (auto& p : v) {
		for (int i = 0; i < 4; ++i) {
			int ny = p.y + dy[i], nx = p.x + dx[i];
			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 9 || s[ny][nx] != 'o') continue;
			int nny = ny + dy[i], nnx = nx + dx[i];
			if (nny < 0 || nny >= 5 || nnx < 0 || nnx >= 9 || s[nny][nnx] != '.') continue;
			s[p.y][p.x] = s[ny][nx] = '.';
			s[nny][nnx] = 'o';
			ii next = solve(s);
			next.second += 1;
			ret = min(ret, next);
			s[p.y][p.x] = s[ny][nx] = 'o';
			s[nny][nnx] = '.';
		}
	}

	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		vector<string> s(5);
		for (int i = 0; i < 5; ++i) {
			char line[10];
			scanf("%s ", line);
			s[i] = line;
		}
		ii ans = solve(s);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}