#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

typedef int lld;
typedef pair<int, int> ii;

int jy, jx;
char visit[1001][1001];

static int ddy[] = {-1,0,0,1,-1,-1,1,1};
static int ddx[] = {0,-1,1,0,-1,1,-1,1};

int dist(int y, int x, int around) {
	memset(visit, 0, sizeof(visit));
	queue<ii> q;
	q.push(make_pair(y, x));
	visit[y][x] = true;
	int ans = 0;
	while (!q.empty()) {
		int qs = q.size();
		while (qs--) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			if (cy == jy && cx == jx) return ans;

			for (int i = 0; i < around; ++i) {
				int ny = cy + ddy[i];
				int nx = cx + ddx[i];
				if (ny < 0 || ny >= 1000 || nx < 0 || nx >= 1000) continue;
				if (visit[ny][nx]) continue;
				q.push(make_pair(ny, nx));
				visit[ny][nx] = true;
			}
		}
		ans++;
	}
	return -1;
}

int main() {
	int by, bx, dy, dx;
	scanf("%d %d %d %d %d %d", &by, &bx, &dy, &dx, &jy, &jx);
	int b = dist(by, bx, 8);
	int d = dist(dy, dx, 4);
	if (b == d) puts("tie");
	else puts(b < d ? "bessie" : "daisy");
	return 0;
}