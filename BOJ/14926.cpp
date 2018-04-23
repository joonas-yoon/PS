#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	bool v[501][501] = {};
	for (int i = 0; i < n; ++i) v[i][i] = true;

	printf("a1 ");
	for (int x = 0; ;) {
		int nx = x;
		for (int i = 0; i < n; ++i) {
			int k = x == n - 1 ? (i + 1) % n : i;
			if (!v[x][k]) {
				nx = k;
				break;
			}
		}
		if (x == nx) break;
		v[x][nx] = v[nx][x] = true;
		x = nx;
		printf("a%d ", x + 1);
	}
	return 0;
}