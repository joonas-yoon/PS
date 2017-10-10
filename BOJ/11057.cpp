#include <bits/stdc++.h>
using namespace std;

// i번째 자리가 k일때
int dp[1001][10];

int n;
int f(int cur, int k) {
	if (cur >= n) return 1;

	int& ret = dp[cur][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = k; i < 10; ++i) {
		ret = (ret + f(cur + 1, i)) % 10007;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0, 0));
	return 0;
}