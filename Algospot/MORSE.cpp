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

static int dy[] = { -1,1,0,0 };
static int dx[] = { 0,0,-1,1 };

int n, m, k;
lld nCr[201][201];

const lld MAX_BOUND = 1e10;

string solve(int n, int m, int k) {
	if (n == 0) return string(m, 'o');

	if (k < nCr[n + m - 1][n - 1])
		return "-" + solve(n - 1, m, k);
	return "o" + solve(n, m - 1, k - nCr[n + m - 1][n - 1]);
}

int main() {
	for (int i = 0; i <= 200; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j)
			nCr[i][j] = min(MAX_BOUND, nCr[i - 1][j - 1] + nCr[i - 1][j]);
	}
	fastio();
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		cout << solve(n, m, k - 1) << '\n';
	}
	return 0;
}