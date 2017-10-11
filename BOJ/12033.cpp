#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int n, tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		vector<int> a(2 * n);
		for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);
		for (int i = (1 << (2 * n)) - 1; i; i--) {
			if (__builtin_popcount(i) != n) continue;

			vector<int> chosen, unchosen;
			for (int j = 0; j < 2 * n; ++j) {
				if (i & (1 << j)) chosen.push_back(a[j]);
				else unchosen.push_back(a[j]);
			}

			bool yes = true;
			for (int j = 0; j < n; ++j) {
				yes &= chosen[j] * 4LL == unchosen[j] * 3LL;
				if (!yes) break;
			}
			if (yes) {
				printf("Case #%d: ", tc);
				for (auto& x : chosen) printf("%d ", x);
				puts("");
				break;
			}
		}
	}
	return 0;
}