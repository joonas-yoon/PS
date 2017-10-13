#include <bits/stdc++.h>
using namespace std;

char s[1001][1001];
int dp[1001][1001];

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) scanf("%s ", s[i]);

	int ans = 0;
	for (int i = 0; i < h; ++i) dp[i][0] = s[i][0] == '1', ans = max(ans, dp[i][0]);
	for (int i = 0; i < w; ++i) dp[0][i] = s[0][i] == '1', ans = max(ans, dp[0][i]);
	for (int i = 1; i < h; ++i) {
		for (int j = 1; j < w; ++j) {
			if (s[i][j] == '1') {
				dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	printf("%d\n", ans * ans);
	return 0;
}