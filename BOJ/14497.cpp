#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

#define INF 987654321

typedef long long lld;
typedef pair<int, int> ii;

int h, w;
int sx, sy, ex, ey;
char a[301][301];
char b[301][301];
bool vis[301][301];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,1,-1 };

bool outOfRange(int y, int x) {
	if (y < 0 || x < 0 || y >= h || x >= w) return true;
	return false;
}

bool dfs(int y, int x) {
	if (outOfRange(y, x)) return false;
	if (vis[y][x]) return false;
	if (a[y][x] == '#') return true;

	vis[y][x] = true;

	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d], nx = x + dx[d];
		if (outOfRange(ny, nx)) continue;

		if (a[ny][nx] == '1') {
			// 파동
			b[ny][nx] = '0';
			continue;
		}
		
		if( dfs(ny, nx) ){
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d %d %d %d ", &h, &w, &sy, &sx, &ey, &ex);
	for (int i = 0; i < h; ++i) {
		scanf("%s ", a[i]);
	}
	a[sy-1][sx-1] = '0';
	memcpy(b, a, sizeof(a));

	if (h < 2 && w < 2) return puts("0"), 0;

	int jumpCount = 0;
	bool jump = false;
	while (!jump) {
		memset(vis, false, sizeof(vis));
		jump |= dfs(sy-1, sx-1);
		jumpCount += 1;
		memcpy(a, b, sizeof(a));
	}
	printf("%d", jumpCount);

	return 0;
}