#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> dp(n + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int& r = dp[i];
		if (i >= 5) r = min(r, 1 + dp[i - 5]);
		if (i >= 2) r = min(r, 1 + dp[i - 2]);
	}
	printf("%d\n", dp[n] < INF ? dp[n] : -1);

	return 0;
}