#include <cstdio>

int n;
bool s[1001][1001];
bool a[1001][1001]; // answer

void makeRow(int row) {
	for (int c = 0; c < n; ++c) {
		if (a[row][c]) {
			s[row][c] ^= 1;
			if (c - 1 >= 0) s[row][c - 1] ^= 1;
			if (c + 1 < n) s[row][c + 1] ^= 1;
		}
	}
}

int main() {
	char str[1001];
	scanf("%d %s", &n, str);
	for (int i = 0; i < n; ++i) s[0][i] = a[0][i] = str[i] == '#';

	makeRow(0);
	for (int r = 1; r < n; ++r) {
		for (int i = 0; i < n; ++i) a[r][i] = s[r][i] = s[r - 1][i];
		for (int i = 0; i < n; ++i) s[r][i] ^= a[r - 1][i];
		makeRow(r);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) putchar(a[i][j] ? '#' : '.');
		puts("");
	}
	return 0;
}