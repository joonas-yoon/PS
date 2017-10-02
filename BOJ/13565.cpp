#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

static int dy[] = { -1, 1, 0, 0 };
static int dx[] = { 0, 0, -1, 1 };

char s[1001][1002];
bool vis[1001][1002];

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		scanf("%s ", s[i]);
	}
	queue<ii> q;
	for (int i = 0; i < w; ++i) {
		if (s[0][i] == '0') q.push({ 0, i }), vis[0][i] = true;
	}

	bool find = false;
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		if (cy == h - 1) {
			find = true;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w || vis[ny][nx] || s[ny][nx] != '0') continue;
			q.push({ ny, nx });
			vis[ny][nx] = true;
		}
	}
	puts(find ? "YES" : "NO");

	return 0;
}