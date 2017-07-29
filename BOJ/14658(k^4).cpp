#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
	int w, h, l, k;
	scanf("%d%d%d%d", &w, &h, &l, &k);
	vector<ii> byX(k), byY(k);
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &byX[i].first, &byX[i].second);
		byY[i] = { byX[i].second, byX[i].first };
	}

	sort(byX.begin(), byX.end());
	sort(byY.begin(), byY.end());

	int ans = 0;
	for (int i = 0; i < k; ++i) {
		// 가로 폭이 L 이하인 점을 잡고, 세로 폭을 확인
		for (int j = i; j < k && byX[j].first - byX[i].first <= l; ++j) {
			int left = byX[i].first, right = byX[j].first;
			for (int yi = 0; yi < k; ++yi) {
				// 세로 폭이 L 이하인 점들을 확인
				int count = 0;
				for (int yj = yi; yj < k && byY[yj].first - byY[yi].first <= l; ++yj) {
					if (!(left <= byY[yi].second && byY[yi].second <= right)) continue;
					if (!(left <= byY[yj].second && byY[yj].second <= right)) continue;
					count += 1;
				}
				ans = max(ans, count);
			}
		}
	}

	printf("%d", k - ans);

	return 0;
}