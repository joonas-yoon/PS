#include <bits/stdc++.h>
using namespace std;

using lld = long long;

int C[4][4] = { // [0] * [1] * ([2] + [3])
	{0, 1, 2, 3},
	{0, 2, 1, 3},
	{2, 3, 0, 1},
	{1, 3, 0, 2}
};

int main() {
	int w, h;
	char s[110][110];
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) scanf("%s ", s[i]);

	lld part[110][110] = {};
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			lld cur = s[i][j] - '0';
			if (i > 0) cur += part[i - 1][j];
			if (j > 0) cur += part[i][j - 1];
			if (i > 0 && j > 0) cur -= part[i - 1][j - 1];
			part[i][j] = cur;
		}
	}

	lld ans = 0LL;
	if (h > 1 && w > 1) {
		for (int y = 1; y < h; ++y) {
			for (int x = 1; x < w; ++x) {
				lld S[4] = {};
				S[0] = part[y - 1][x - 1];
				S[1] = part[y - 1][w - 1] - S[0];
				S[2] = part[h - 1][x - 1] - S[0];
				S[3] = part[h - 1][w - 1] - S[0] - S[1] - S[2];
				for (int i = 0; i < 4; ++i)
					ans = max(ans, S[C[i][0]] * S[C[i][1]] * (S[C[i][2]] + S[C[i][3]]));
			}
		}
	}


	// shape: ll
	for (int i = 1; i < w - 1; ++i) {
		for (int j = i + 1; j < w; ++j) {
			lld S[3] = {};
			S[0] = part[h - 1][i - 1];
			S[1] = part[h - 1][j - 1] - S[0];
			S[2] = part[h - 1][w - 1] - S[0] - S[1];
			ans = max(ans, S[0] * S[1] * S[2]);
		}
	}

	// shaep: =
	for (int i = 1; i < h - 1; ++i) {
		for (int j = i + 1; j < h; ++j) {
			lld S[3] = {};
			S[0] = part[i - 1][w - 1];
			S[1] = part[j - 1][w - 1] - S[0];
			S[2] = part[h - 1][w - 1] - S[0] - S[1];
			ans = max(ans, S[0] * S[1] * S[2]);
		}
	}

	printf("%lld\n", ans);
	return 0;
}