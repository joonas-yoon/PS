#include <bits/stdc++.h>
using namespace std;

static int dy[] = { -1,0,1,0 };
static int dx[] = { 0,1,0,-1 };

int main() {
	int n, m;
	scanf("%d %d ", &m, &n);
	int cy = 0, cx = 0, d = 1;
	while (n--){
		int x;
		char s[10];
		scanf("%s %d ", s, &x);
		if (*s == 'T') {
			if (x == 0) d = (d + 1) % 4;
			else d = (d + 3) % 4;
		}
		else {
			int ny = cy + x * dy[d], nx = cx + x * dx[d];
			if (ny < 0 || ny > m || nx < 0 || nx > m) return puts("-1"), 0;
			cy = ny, cx = nx;
		}
	}
	printf("%d %d\n", cx, cy);
	return 0;
}