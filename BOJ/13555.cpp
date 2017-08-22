#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 5 * 1e6;

int N = 100000;
int t[200001];

void update(int i, int val) {
	for (val %= MOD, t[i += N] = val; i > 1; i >>= 1) {
		t[i >> 1] = (t[i] + t[i ^ 1]) % MOD;
	}
}

int query(int l, int r) {
	int sum = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) sum = (sum + t[l++]) % MOD;
		if (r & 1) sum = (sum + t[--r]) % MOD;
	}
	return sum;
}

/**
dp[i][j] = sum(dp[i-1][k]) for all k < j, a[k] < a[j]
dp[i-1][*] 가 계산되어 있다면 dp[i][j] 를 계산할 때 적절한 자료구조가 있어서
1. 자료구조에서 1 ~ a[j] - 1까지 합 계산
2. 자료구조에 key a[j], value dp[i-1][j] 추가
by @koosaga
*/

int main() {
	int n, k, a[100001];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int dp[100001] = {};
	for (int i = 0; i < n; ++i) dp[i] = 1;
	for (int i = 2; i <= k; ++i) {
		memset(t, 0, sizeof(t));
		for (int j = 0; j < n; ++j) {
			update(a[j], t[N + a[j]] + dp[j]);
			dp[j] = query(1, a[j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) ans = (ans + dp[i]) % MOD;
	printf("%d", ans);

	return 0;
}