#include <cstdio>
#include <cstring> // memset
#include <utility> // pair
#include <queue>
using namespace std;

typedef pair<int, int> ii;

static int dx[] = {-1,-1,-1,0,0,1,1,1};
static int dy[] = {-1,0,1,-1,1,-1,0,1};

int h, w;
int grid[51][51];
bool visit[51][51];

int bfs(int y, int x) {
	if (visit[y][x] || grid[y][x] == 0) return 0;

	queue<ii> q;
	q.push(make_pair(y, x));
	
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (grid[ny][nx] == 0 || visit[ny][nx]) continue;

			visit[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}

	return 1;
}

int main() {
	while (~scanf("%d %d", &w, &h) && h && w) {
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j)
				scanf("%d", &grid[i][j]);
		}

		int count = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				count += bfs(i, j);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}