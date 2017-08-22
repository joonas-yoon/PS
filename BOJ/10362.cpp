#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1,0,1,0 };
static int dx[] = { 0,1,0,-1 };

#define MID 200
int c[400][400];

int main() {
	int T, tcase = 0;
	scanf("%d", &T);
	while (T--) {
		int x, y, d = 2;
		char s[150] = {};
		scanf("%d %d %s ", &x, &y, s);
		memset(c, 0, sizeof(c));
		x += MID, y += MID;
		c[y][x]++;
		for (int i = 0; s[i]; ++i) {
			if (s[i] == 'F') {
				x += dx[d], y += dy[d];
				c[y][x]++;
			}
			else if (s[i] == 'R') d = (d + 3) % 4;
			else d = (d + 1) % 4;
		}

		int ans = 0;
		for (int i = 0; i < 400; ++i)
			for (int j = 0; j < 400; ++j)
				ans += c[i][j] > 1;

		printf("Case #%d: %d %d %d\n", ++tcase, x - MID, y - MID, ans);
	}
	return 0;
}