#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

const int INF = 0x3f3f3f3f;

lld comb[201][201];

string solve(int n, int m, int k) {
	if (n + m == 0) return "";
	lld cnt = comb[n - 1 + m][m];
	if (k <= cnt)
		return "a" + solve(n - 1, m, k);
	return "z" + solve(n, m - 1, k - cnt);
}

int main() {
	for (int i = 0; i <= 200; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			comb[i][j] = min(comb[i][j], (lld)INF);
		}
	}

	int n, m, k;
	while (~scanf("%d %d %d", &n, &m, &k)) {
		if (comb[n+m][m] < k)
			puts("-1"), 0;
		else
			puts(solve(n, m, k).c_str());
	}

	return 0;
}
