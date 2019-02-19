#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[30][30];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	}

	bool perm[30] = {};
	for (int i = 0; i < 3; ++i) perm[m - 1 - i] = 1;

	int ans = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int sel = 0;
			for (int j = 0; j < m; ++j)
				if (perm[j]) sel = max(sel, a[i][j]);
			sum += sel;
		}
		ans = max(ans, sum);
	} while (next_permutation(perm, perm + m));

	printf("%d\n", ans);

	return 0;
}