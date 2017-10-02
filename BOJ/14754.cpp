#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int rowMax[1001], colMax[1001];
int h, w, a[1001][1001];

int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d ", &a[i][j]);
			rowMax[i] = max(rowMax[i], a[i][j]);
			colMax[j] = max(colMax[j], a[i][j]);
		}
	}

	lld ans = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (a[i][j] != rowMax[i] && a[i][j] != colMax[j]) {
				ans += a[i][j];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}