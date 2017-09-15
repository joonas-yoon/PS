#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, p;
	while (cin >> s >> p) {
		int sl = s.length(), pl = p.length();
		vector<vector<int>> dp(sl + 1, vector<int>(pl + 1, 0));
		for (int i = 1; i <= sl; ++i) {
			for (int j = 1; j <= pl; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s[i - 1] == p[j - 1]) 
					dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
			}
		}
		printf("%d\n", dp[sl][pl]);
	}
	return 0;
}