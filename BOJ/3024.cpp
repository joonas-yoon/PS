#include <cstdio>

static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };

int n;
char s[31][31];

int cnt(int y, int x, int d) {
	char ch = s[y][x];
	int sum = 0, i = 0;
	for (; y >= 0 && y < n && x >= 0 && x < n; y += dy[d], x += dx[d]) {
		sum += s[y][x] == ch;
		if (i++ > 0 && s[y][x] != ch) break;
	}
	return sum;
}

bool win(int y, int x) {
	for (int d = 0; d < 4; ++d) {
		if (cnt(y, x, d) + cnt(y, x, (d + 4) % 8) - 1 >= 3)
			return true;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", s[i]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] != '.' && win(i, j)) {
				putchar(s[i][j]);
				return 0;
			}
		}
	}
	puts("ongoing");

	return 0;
}