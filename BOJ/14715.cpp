#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

const int MAX_N = 1e6 + 1;

bool notPrime[MAX_N];

int dp[MAX_N];

int solve(int k) {
	if (k < 2 || !notPrime[k]) return 0;

	int& ret = dp[k];
	if (ret != -1) return ret;
	ret = INF;
	for (lld j = 2; j*j <= k; ++j) {
		if (k % j == 0)
			ret = min(ret, 1 + max(solve(j), solve(k / j)));
	}
	return ret;
}

int main() {
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= MAX_N; ++i) {
		if (notPrime[i]) continue;
		for (lld j = (lld)i*i; j <= MAX_N; j += i) notPrime[j] = true;
	}

	memset(dp, -1, sizeof(dp));

	int n;
	scanf("%d", &n);
	printf("%d\n", solve(n));

	return 0;
}