#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int INF = 0x3F3F3F3F;

vector<ii> shape[7];

ii rotate(ii point) {
	return { point.second, -point.first };
}

char kinds[5][2][5] = {
	{ "####" },
	{ "##","##" },
	{ "###","..#" },
	{ "##",".##" },
	{ "###",".#" }
};

int main() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 2; ++j) {
			int len = strlen(kinds[i][j]);
			if (len < 1) break;
			for (int k = 0; k < len; ++k) {
				if (kinds[i][j][k] == '#') shape[i].push_back({ j, k });
			}
		}
	}

	int tc = 0, n;
	while (~scanf("%d", &n) && n) {
		int a[101][101];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &a[i][j]);

		int ans = -INF;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < 5; ++k) {
					for (int d = 0; d < 4; ++d) {
						int sum = 0;
						for (auto& p : shape[k]) {
							ii cur = p;
							for (int _ = 0; _ < d; ++_) cur = rotate(cur);
							int ny = i + cur.first, nx = j + cur.second;
							if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
								sum = -INF;
								break;
							}
							sum += a[ny][nx];
						}
						ans = max(ans, sum);
					}
				}
			}
		}
		printf("%d. %d\n", ++tc, ans);
	}

	return 0;
}