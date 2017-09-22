#include <bits/stdc++.h>
using namespace std;

using lld = long long;
using llu = unsigned long long;
using ii = pair<int, int>;
using ll = pair<lld, lld>;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

char s[1001][1001];
int fd[1001][1001];
int md[1001][1001];

int h, w;

bool inRange(int y, int x) {
	return 0 <= y && y < h && 0 <= x && x < w;
}

int main() {
	scanf("%d %d ", &h, &w);
	queue<ii> fire, man;
	for (int i = 0; i < h; ++i) {
		scanf("%s ", s[i]);
		for (int j = 0; j < w; ++j) {
			fd[i][j] = md[i][j] = INF;
			if (s[i][j] == 'J') man.push({ i, j }), md[i][j] = 0;
			if (s[i][j] == 'F') fire.push({ i, j }), fd[i][j] = 0;
			if (s[i][j] != '#') s[i][j] = '.';
		}
	}

	int dist = 0;
	while (!fire.empty()) {
		int qs = fire.size();
		while (qs--) {
			ii f = fire.front();
			fire.pop();

			for (int i = 0; i < 4; ++i) {
				int ny = f.first + dy[i], nx = f.second + dx[i];
				if (!inRange(ny, nx) || s[ny][nx] != '.' || dist + 1 >= fd[ny][nx]) continue;
				fd[ny][nx] = dist + 1;
				fire.push({ ny, nx });
			}
		}
		++dist;
	}

	bool find = false;
	dist = 0;
	while (!man.empty()) {
		int qs = man.size();
		while (qs--) {
			ii f = man.front();
			man.pop();

			if (f.first == 0 || f.first == h - 1 || f.second == 0 || f.second == w - 1) {
				find = true;
				break;
			}

			for (int i = 0; i < 4; ++i) {
				int ny = f.first + dy[i], nx = f.second + dx[i];
				if (!inRange(ny, nx) || s[ny][nx] != '.' || dist + 1 >= md[ny][nx] || dist + 1 >= fd[ny][nx]) continue;
				md[ny][nx] = dist + 1;
				man.push({ ny, nx });
			}
		}
		if (find) break;
		++dist;
	}
	if (find)
		printf("%d\n", dist + 1);
	else
		puts("IMPOSSIBLE");

	return 0;
}