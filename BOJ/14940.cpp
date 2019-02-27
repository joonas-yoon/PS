#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

static int dy[] = {-1,0,1,0};
static int dx[] = {0,1,0,-1};

int h, w;
int D[1001][1001];
int a[1001][1001];

int main() {
	queue<ii> q;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2) {
				q.push(make_pair(i, j));
				D[i][j] = 0;
			} else {
				D[i][j] = a[i][j] == 0 ? 0 : -1;
			}
		}
	}

	int dist = 1;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int d = 0; d < 4; ++d) {
				int ny = y + dy[d], nx = x + dx[d];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (a[ny][nx] != 1 || D[ny][nx] != -1) continue;
				D[ny][nx] = dist;
				q.push(make_pair(ny, nx));
			}
		}
		dist++;
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			printf("%d ", D[i][j]);
		puts("");
	}

	return 0;
}