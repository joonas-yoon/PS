#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

// 정수 n일 때 나올 수 있는 연산의 최대 횟수
int solve(int n) {
	if (n == 1) return 0;

	if (dp[n] != -1) return dp[n];

	int ans = 1 + solve(n - 1);
	if (n % 3 == 0) ans = min(ans, 1 + solve(n / 3));
	if (n % 2 == 0) ans = min(ans, 1 + solve(n / 2));
	return dp[n] = ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	scanf("%d", &n);
	printf("%d", solve(n));
	return 0;
}