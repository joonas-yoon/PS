#include <bits/stdc++.h>
using namespace std;

int o[4][4] = {
	{1, 0, 1, 0},
	{0, 0, 0, 0},
	{1, 1, 1, 1},
	{0, 1, 0, 1}
};

int main() {
	int n, a[101][101];
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);

		int r[101] = {}, c[101] = {};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				r[i] += a[i][j];
				c[j] += a[i][j];
			}
		}

		int rodd = 0, codd = 0;
		for (int i = 0; i < n; ++i) rodd += r[i] % 2;
		for (int i = 0; i < n; ++i) codd += c[i] % 2;

		if (rodd == 0 && codd == 0) {
			puts("OK");
			continue;
		}

		if (rodd == 1 && codd == 1) {
			int ry, rx;
			for (int i = 0; i < n; ++i) if (r[i] % 2) { ry = i; break; }
			for (int i = 0; i < n; ++i) if (c[i] % 2) { rx = i; break; }
			printf("Change bit (%d,%d)\n", ry + 1, rx + 1);
		}
		else 
			puts("Corrupt");
	}
	return 0;
}