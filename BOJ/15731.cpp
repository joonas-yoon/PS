#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n;
int dp[5001][5001];
char s[5001];

// dp[pos][indent] := pos번째 문자까지 봤을 때, indent라면 그 때의 경우의 수
int f(int pos, int indent) {
	if (indent < 0) return 0;
	if (pos >= n - 1) return 1;

	int& ret = dp[pos][indent];
	if (ret != -1) return ret;

	ret = 0;
	if (s[pos] == 'e') {
		// 그대로 쓰거나
		ret = (ret + f(pos + 1, indent)) % MOD;
		// 내어쓰거나
		ret = (ret + f(pos, indent - 1)) % MOD;
	}
	else {
		ret = f(pos + 1, indent + 1);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	scanf("%s", s);
	n = strlen(s);
	printf("%d\n", f(0, 0));

	return 0;
}