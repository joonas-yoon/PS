#include <cstdio>

const int n = 9;

int a[10][10];

bool correct() {
	for (int y = 0; y < n; ++y) {
		bool fr[10] = {};
		for (int i = 0; i < n; ++i) {
			if (fr[a[y][i]]) return false;
			fr[a[y][i]] = true;
		}
	}
	for (int x = 0; x < n; ++x) {
		bool fr[10] = {};
		for (int i = 0; i < n; ++i) {
			if (fr[a[i][x]]) return false;
			fr[a[i][x]] = true;
		}
	}
	for (int y = 0; y < n; y += 3) {
		for (int x = 0; x < n; x += 3) {
			bool fr[10] = {};
			for (int i = 0; i < n/3; ++i) {
				for (int j = 0; j < n/3; ++j) {
					if (fr[a[y + i][x + j]]) return false;
					fr[a[y + i][x + j]] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	int T, tc = 0;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);
		printf("Case %d: %sCORRECT\n", ++tc, correct() ? "" : "IN");
	}
	return 0;
}