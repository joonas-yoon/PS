#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

int main() {
	int h, w;
	char g[21][21];

	scanf("%d %d ", &h, &w);
	for (int i = 0; i < h; ++i) scanf("%s ", g[i]);

	int ans = h * w;
	FOR(ay, h) FOR(ax, w) {
		FOR(by, h) FOR(bx, w) {
			if ((ay == by && ax == bx) || g[ay][ax] != '0' || g[by][bx] != '0') continue;

			int d = 0;
			FOR(y, h) {
				FOR(x, w) {
					if (g[y][x] == '1') {
						int dist = min(abs(y - ay) + abs(x - ax), abs(y - by) + abs(x - bx));
						d = max(d, dist);
					}
				}
			}
			ans = min(ans, d);
		}
	}
	printf("%d\n", ans);

	return 0;
}