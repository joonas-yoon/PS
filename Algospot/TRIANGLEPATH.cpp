#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, a[100][100]={};
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				scanf("%d", &a[i][j]);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				int m = a[i - 1][j];
				if (j - 1 >= 0) m = max(m, a[i - 1][j - 1]);
				a[i][j] += m;
			}
		}

		printf("%d\n", *max_element(a[n - 1], a[n - 1] + n));
	}
	return 0;
}