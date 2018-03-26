#include <bits/stdc++.h>
using namespace std;

char solve(int ab, int ba) {
	if (!ab && !ba) return 0;
	return ab ? -1 : 1;
}

int main() {
	int n, k, a, b;
	bool v[405][405] = {};
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &a, &b);
		v[a - 1][b - 1] = true;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				v[i][j] |= v[i][k] & v[k][j];
			}
		}
	}

	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(v[a - 1][b - 1], v[b - 1][a - 1]));
	}
	return 0;
}