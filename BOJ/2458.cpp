#include <cstdio>

int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	bool g[501][501] = {};
	while (e--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a][b] = true;
	}

	for (int i = 1; i <= v; ++i) g[i][i] = true;

	for (int k = 1; k <= v; ++k)
		for (int i = 1; i <= v; ++i)
			for (int j = 1; j <= v; ++j)
				g[i][j] |= g[i][k] && g[k][j];

	int ans = 0;
	for (int i = 1; i <= v; ++i) {
		bool yes = true;
		for (int j = 1; j <= v; ++j) yes &= g[i][j] || g[j][i];
		ans += yes;
	}
	printf("%d\n", ans);

	return 0;
}