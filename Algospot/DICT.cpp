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

int bino[201][101];
const int MAX_N = 1e9;

int nCr(int n, int r) {
	if (n == 0 || r == 0 || n == r) return 1;
	int& ret = bino[n][r];
	if (ret) return ret;
	return ret = min(MAX_N, nCr(n - 1, r) + nCr(n - 1, r - 1));
}

string solve(int n, int m, int k) {
	if (n == 0) return string(m, 'b');
	int g = nCr(n + m - 1, n - 1);
	if (k > g) return "b" + solve(n, m - 1, k - g);
	return "a" + solve(n - 1, m, k);
}

int main() {
	fastio();
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (k > nCr(n + m, n)) cout << "NONE\n";
		else cout << solve(n, m, k) << '\n';
	}
	return 0;
}