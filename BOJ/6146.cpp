#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dy[] = { -1,1,0,0,-1,1,-1,1 };
int dx[] = { 0,0,-1,1,-1,1,1,-1 };

const int MID = 500;

int main() {
	int x, y, n;
	scanf("%d %d %d", &x, &y, &n);
	x += MID;
	y += MID;

	bool vis[1001][1001] = {};
	while (n--) {
		int r, c;
		scanf("%d %d", &c, &r);
		vis[MID + r][MID + c] = true;
	}
	queue<ii> q;
	q.push({ MID, MID });
	vis[MID][MID] = true;
	int dist = 0;
	while (!q.empty()) {
		int qs = q.size();
		bool find = false;
		while (qs--) {
			int cy = q.front().first, cx = q.front().second;
			q.pop();

			if (cy == y && cx == x) {
				find = true;
				break;
			}

			for (int i = 0; i < 4; ++i) {
				int ny = cy + dy[i], nx = cx + dx[i];
				if (ny < 0 || nx < 0 || ny >= 1000 || nx >= 1000 || vis[ny][nx]) continue;
				vis[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
		if (find) break;
		++dist;
	}
	printf("%d", dist);

	return 0;
}