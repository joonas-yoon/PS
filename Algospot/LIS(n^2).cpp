#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a, vector<int>& dp, int cur) {
	if (cur >= a.size()) return 0;
	int& ret = dp[cur];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = cur + 1; i < a.size(); ++i) {
		if (a[cur] < a[i]) {
			ret = max(ret, 1 + LIS(a, dp, i));
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n + 1, 0), dp(n + 1, -1);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		printf("%d\n", LIS(a, dp, 0));
	}
	return 0;
}