#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false);

typedef long long lld;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int dp[101][101];

int jlis(vector<lld>& a, vector<lld>& b, int i, int j) {
	int& ret = dp[i + 1][j + 1];
	if (ret != -1) return ret;
	ret = 0;
	lld maxNum = max(i == -1 ? -LINF : a[i], j == -1 ? -LINF : b[j]);
	for (int ii = i + 1; ii < a.size(); ++ii) {
		if (maxNum < a[ii])
			ret = max(ret, 1 + jlis(a, b, ii, j));
	}
	for (int jj = j + 1; jj < b.size(); ++jj) {
		if (maxNum < b[jj])
			ret = max(ret, 1 + jlis(a, b, i, jj));
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<lld> a(n), b(m);
		for (auto& x : a) scanf("%lld", &x);
		for (auto& x : b) scanf("%lld", &x);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", jlis(a, b, -1, -1));
	}
	return 0;
}