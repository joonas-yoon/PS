#include <cstdio>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int a[3][2] = {};
	while (n--) {
		int s, y;
		scanf("%d %d", &s, &y);
		y = (y - 1) / 2;
		if (y < 1) a[y][0] += 1;
		else a[y][s] += 1;
	}
	int ans = (a[0][0] + k - 1) / k;
	for (int i = 1; i < 3; ++i) {
		for(int j=0; j<2; ++j)
			ans += (a[i][j] + k - 1) / k;
	}
	printf("%d\n", ans);

	return 0;
}