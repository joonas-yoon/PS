#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> dp(n, INF);
	dp[0] = 0;
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		for (int j = 1; j <= x && i + j < n; ++j) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	printf("%d\n", dp[n - 1] < INF ? dp[n - 1] : -1);
	return 0;
}