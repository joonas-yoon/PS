#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

vector<ii> shape[7];

ii rotate(ii point) {
	return { point.second, -point.first };
}

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	int a[501][501];
	for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
			scanf("%d", &a[i][j]);

	char kinds[7][2][5] = {
		{"####"},
		{"##","##"},
		{"###","#"}, {"###","..#"},
		{".##","##"}, {"##",".##"},
		{".#","###"}
	};

	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 2; ++j) {
			int len = strlen(kinds[i][j]);
			if (len < 1) break;
			for (int k = 0; k < len; ++k) {
				if (kinds[i][j][k] == '#') shape[i].push_back({ j, k });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			// 각 점마다
			for (int k = 0; k < 7; ++k) {
				// 7개의 모양에 대해 전부 확인
				for (int d = 0; d < 4; ++d) {
					int sum = 0;
					for (auto& p : shape[k]) {
						ii cur = p;
						for (int ii = 0; ii < d; ++ii) cur = rotate(cur);
						int ny = i + cur.first, nx = j + cur.second;
						if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
							sum = 0;
							break;
						}
						sum += a[ny][nx];
					}
					ans = max(ans, sum);
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}