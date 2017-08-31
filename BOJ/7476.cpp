#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int, int> ii;
typedef pair<lld, lld> ll;

const int INF = 0x3F3F3F3F;
const lld LINF = 0x3F3F3F3F3F3F3F3F;
const lld MOD = 1e9 + 7;

int n, m;
lld a[501], b[501];
int lcs[501][501];
ii nxt[501][501];

int solve(int ai, int bj) {
	int& ret = lcs[ai][bj];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = ai + 1; i <= n; ++i) {
		if (a[ai] >= a[i]) continue;
		for (int j = bj + 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				int val = 1 + solve(i, j);
				if (ret < val) {
					ret = val;
					nxt[ai][bj] = { i, j };
				}
                break;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) scanf("%lld", &b[i]);

	a[0] = b[0] = -LINF;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			nxt[i][j] = { 0, 0 };
	memset(lcs, -1, sizeof(lcs));

	printf("%d\n", solve(0, 0));
	ii cur = nxt[0][0];
	while (cur.first) {
		printf("%d ", a[cur.first]);
		cur = nxt[cur.first][cur.second];
	}
	puts("");
	return 0;
}