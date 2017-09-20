#include <cstdio>

int h, w;
bool tile[26][26];

int solve(int cur) {
	int y = cur / w, x = cur % w;
	if (cur >= h*w) return 1;

	int r = solve(cur + 1);
	if (y >= 1 && x >= 1 && tile[y - 1][x - 1] && tile[y - 1][x] && tile[y][x - 1]);
	else {
		tile[y][x] = true;
		r += solve(cur + 1);
		tile[y][x] = false;
	}
	return r;
}

int main() {
	scanf("%d %d", &h, &w);
	printf("%d\n", solve(0));
	return 0;
}