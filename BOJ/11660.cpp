#include <cstdio>

int table[1025][1025];
int sum[1025][1025];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			scanf("%d", &table[y][x]);
			sum[y][x] += sum[y][x - 1] + table[y][x];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			sum[j][i] += sum[j - 1][i];
		}
	}

	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1]);
	}
	return 0;
}