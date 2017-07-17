#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[501][501];

int countNine(int n) {
	int r = 0;
	while (n > 0) {
		r += n % 10 == 9;
		n /= 10;
	}
	return r;
}

int main() {
	int h, w;
	scanf("%d %d", &h, &w);

	int allNines = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf("%d", &a[i][j]);
			allNines += countNine(a[i][j]);
		}
	}

	int ans = 0;

	for (int i = 0; i < h; ++i) {
		int sum = 0;
		for (int j = 0; j < w; ++j) {
			sum += countNine(a[i][j]);
		}
		ans = max(ans, sum);
	}

	for (int i = 0; i < w; ++i) {
		int sum = 0;
		for (int j = 0; j < h; ++j) {
			sum += countNine(a[j][i]);
		}
		ans = max(ans, sum);
	}

	printf("%d", allNines - ans);

	return 0;
}