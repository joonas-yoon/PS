#include <cstdio>

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int main() {
	int h, w;
	while (~scanf("%d %d ", &h, &w) && h) {
		char s[101][101];
		for (int i = 0; i < h; ++i) gets(s[i]);
		int dy[] = { -1,-1,-1,0,0,1,1,1 };
		int dx[] = { -1,0,1,-1,1,-1,0,1 };
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (s[i][j] == '*') putchar('*');
				else {
					int k = 0;
					for (int d = 0; d < 8; ++d) {
						int ny = i + dy[d], nx = j + dx[d];
						if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
						k += s[ny][nx] == '*';
					}
					printf("%d", k);
				}
			}
			puts("");
		}
	}
	return 0;
}