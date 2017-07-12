#include <cstdio>

const int n = 19;
int board[20][20];

int dy[] = { 1,1,1,0 };
int dx[] = { -1,0,1,1 };

bool outOfRange(int r, int c) { return r < 0 || r >= n || c < 0 || c >= n; }

bool win(int y, int x) {
	for (int d = 0; d < 4; ++d) {
		int ret = -1;
		for (int r = y, c = x; !outOfRange(r, c) && board[r][c] == board[y][x]; r += dy[d], c += dx[d]) ret++;
		for (int r = y, c = x; !outOfRange(r, c) && board[r][c] == board[y][x]; r -= dy[d], c -= dx[d]) ret++;
		if (ret == 5) return true;
	}
	return false;
}

int main() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) scanf("%d ", &board[i][j]);
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (board[y][x] == 0) continue;
			if (win(y, x)) {
				return printf("%d\n%d %d", board[y][x], y + 1, x + 1), 0;
			}
		}
	}
	puts("0");

	return 0;
}