#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int bene[25][301] = {};
	for (int cost, i = 0; i < m; ++i) {
		scanf("%d", &cost);
		for (int j = 1; j <= n; ++j) scanf("%d", &bene[j][cost]);
	}
    
	int dp[25][301] = {}, trace[25][301] = {};
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; j - k >= 0; ++k) {
				if (dp[i][j] < dp[i - 1][j - k] + bene[i][k]) {
					dp[i][j] = dp[i - 1][j - k] + bene[i][k];
					trace[i][j] = k; /// j원일때는 k원을 사용하면 이익이 높아진다.
				}
			}
		}
	}

	printf("%d\n", dp[n][m]);
	stack<int> s;
	while (n > 0) {
		s.push(trace[n][m]);
		m -= trace[n--][m];
	}
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}