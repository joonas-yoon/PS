#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		int n;
		scanf("%d", &n);
		vector<int> a(2 * n);
		for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);

		stack<int> ans;
		vector<bool> chosen(2 * n, false);
		for (int i = 2 * n - 1; i >= 0; --i) {
			if (chosen[i]) continue;
			int origin = a[i];
			for (int j = i - 1; j >= 0; --j) {
				if (chosen[j]) continue;
				int sale = a[j];
				if (sale * 4LL == origin * 3LL) {
					chosen[i] = chosen[j] = true;
					ans.push(sale);
					break;
				}
			}
		}

		printf("Case #%d: ", tc);
		for (; !ans.empty(); ans.pop()) printf("%d ", ans.top());
		puts("");
	}
	return 0;
}