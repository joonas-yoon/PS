#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int n;
	scanf("%d", &n);
	bool v[501][501] = {};
	int bot = INF, top = 0, left = INF, right = 0;
	while (n--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = y1; i < y2; ++i) {
			for (int j = x1; j < x2; ++j) {
				v[i][j] = true;
			}
		}
		top = max(top, y2);
		bot = min(bot, y1);
		left = min(left, x1);
		right = max(right, x2);
	}
	int area = 0;
	for (int i = bot; i <= top; ++i) {
		for (int j = left; j <= right; ++j) {
			area += v[i][j];
		}
	}
	printf("%d\n", area);
	return 0;
}