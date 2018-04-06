#include <cstdio>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int g[1002], s[1002], b[1002];
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		scanf("%d %d %d", &g[x], &s[x], &b[x]);
	}

	int rank = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == k) continue;
		if (g[i] > g[k]) rank++;
		else if (g[i] == g[k] && s[i] > s[k]) rank++;
		else if (g[i] == g[k] && s[i] == s[k] && b[i] > b[k]) rank++;
	}
	printf("%d\n", rank + 1);

	return 0;
}