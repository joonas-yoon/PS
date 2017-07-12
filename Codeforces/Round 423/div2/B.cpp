#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long lld;

typedef pair<int, int> ii;

int H, W;
char cell[101][101];

int main() {
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; ++i) scanf("%s ", cell[i]);

	bool allWhite = true;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			allWhite &= cell[i][j] != 'B';
			if (!allWhite) break;
		}
		if (!allWhite) break;
	}
	if (allWhite) return puts("1"), 0;

	int top = H, bot = 0, left = W, right = 0;
	int blackCount = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (cell[i][j] == 'B') {
				top = min(top, i);
				bot = max(bot, i);
				left = min(left, j);
				right = max(right, j);
				blackCount++;
			}
		}
	}

	int n = max(right - left + 1, bot - top + 1);
	if (H < n || W < n) return puts("-1");

	printf("%d", n*n - blackCount);
	return 0;
}