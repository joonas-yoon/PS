#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <set>
using namespace std;

typedef long long lld;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

#define INF 987654321
#define LINF (LLONG_MAX>>1)

typedef pair<int, int> ii;

int n, a[51];

int dp[50][500001];

int solve(int i, int diff) {
	if (i >= n) {
		return diff == 0 ? 0 : -INF;
	}

	int& ret = dp[i][abs(diff)];
	if (ret != -1) return ret;

	// 이 블럭을 사용하지 않는다.
	ret = solve(i + 1, diff);

    // 왼쪽 탑에 두면 (+), 오른쪽 탑에 두면 (-)
	return ret = max(ret, a[i] + max(
		solve(i + 1, diff + a[i]),
		solve(i + 1, diff - a[i])
	));
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int ans = solve(0, 0) / 2;
	printf("%d", ans > 0 ? ans : -1);
	return 0;
}