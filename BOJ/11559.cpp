#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int H = 12, W = 6;
char g[12][7];
bool v[12][7];

int Count(int y, int x, char ch) {
	if (y < 0 || y >= H || x < 0 || x >= W) return 0;
	if (v[y][x] || g[y][x] != ch) return 0;
	v[y][x] = true;
	int s = 1;
	for (int d = 0; d < 4; ++d) s += Count(y + dy[d], x + dx[d], ch);
	return s;
}

void Update(int y, int x, char ch){
	if (y < 0 || y >= H || x < 0 || x >= W || g[y][x] != ch) return;
	g[y][x] = '.';
	for (int d = 0; d < 4; ++d) Update(y + dy[d], x + dx[d], ch);
}

void Gravity() {
	for (int r = 0; r < W; ++r) {
		int bottom = H - 1;
		char str[13] = {};
		for (int h = H - 1; h >= 0; --h) {
			if (g[h][r] != '.') str[bottom--] = g[h][r];
			g[h][r] = '.';
		}
		for (int h = H - 1; h > bottom; --h) g[h][r] = str[h];
	}
}

int main() {
	for (int i = 0; i < H; ++i) gets(g[i]);

	int answer = 0;
	bool changed = false;
	do {
		changed = false;
		for (int i = H - 1; i >= 0; --i) {
			for (int j = 0; j < W; ++j) {
				memset(v, false, sizeof(v));
				if (g[i][j] != '.' && Count(i, j, g[i][j]) >= 4) {
					Update(i, j, g[i][j]);
					changed = true;
				}
			}
		}
		Gravity();
		answer += changed;
	} while (changed);

	printf("%d", answer);

	return 0;
}

/*
......
......
......
......
......
...B..
.GGBG.
.BRBG.
.BRRB.
.BRGG.
BRRRB.
RRRRB.
= 3
*/