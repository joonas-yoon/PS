#include <bits/stdc++.h>
using namespace std;

#define fastio() std::ios::sync_with_stdio(false)

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;
typedef tuple<int, int, int> iii;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int n;
vector<vector<int>> a;
ii dp[101][101];

// {경로의 최대 길이, 그러한 것의 개수}
ii solve(int row, int col) {
	if (row >= n || col >= a[row].size()) return { 0, 0 };
	if (row == n - 1) return { a[row][col], 1 };

	ii& ret = dp[row][col];
	if (ret != make_pair(-1, -1)) return ret;

	ret = { -INF, 0 };
	ii down = solve(row + 1, col);
	ii right = solve(row + 1, col + 1);
	ret = max(down, right);
	ret.first += a[row][col];
	if (down.first == right.first) {
		ret.second = down.second + right.second;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a = vector<vector<int>>(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(i + 1);
			for (int j = 0; j <= i; ++j) {
				scanf("%d", &a[i][j]);
				dp[i][j] = { -1, -1 };
			}
		}
		printf("%d\n", solve(0, 0).second);
	}
	return 0;
}