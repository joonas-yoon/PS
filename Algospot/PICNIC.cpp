#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

bool isFriend[11][11];

int dp[6][1 << 10];

int solve(int n, int k, int bit) {
	if (bit == 0) return 1;

	int& ret = dp[k][bit];
	if (ret != -1) return ret;

	int f = -1;
	for (int i = 0; i < n; ++i) {
		if (bit & (1 << i)) {
			f = i;
			break;
		}
	}
	// 고를 수 있는 친구가 없으면
	if (f == -1) return 1;

	ret = 0;
	int next_bit = bit & ~(1 << f);
	for (int i = f + 1; i < n; ++i) {
		if ((bit & (1 << i)) && isFriend[f][i]) {
			ret += solve(n, k - 1, next_bit & ~(1 << i));
		}
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(isFriend, false, sizeof(isFriend));
		memset(dp, -1, sizeof(dp));

		int n, m;
		scanf("%d %d", &n, &m);
		for (int x, y, i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			isFriend[x][y] = true;
			isFriend[y][x] = true;
		}
		printf("%d\n", solve(n, n / 2, (1 << n) - 1));
	}
	return 0;
}