#include <cstdio>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
#define gets(s) gets_s(s)
#endif

typedef long long lld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;

lld a[1001], b[2001];
int n, k, position;
lld dp[1001][2001];

// 사람 a[i]가 열쇠 b[j]를 가지고 갈 경우
lld solve(int i, int j) {
	if (i >= n) return 0; // all people arrived with key
	if (j >= k) return LINF;

	lld& ret = dp[i][j];
	if (ret != -1) return ret;

	return ret = min(
		// get a key
		max(solve(i+1, j+1), abs(a[i] - b[j]) + abs(b[j] - position)),
		// choose next key
		solve(i, j+1)
	);
}

int main() {
	scanf("%d %d %d", &n, &k, &position);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for (int i = 0; i < k; ++i) scanf("%lld", &b[i]);

	sort(a, a + n);
	sort(b, b + k);

	memset(dp, -1, sizeof(dp));
	printf("%lld", solve(0, 0));

	return 0;
}