#include <bits/stdc++.h>
using namespace std;

using lld = long long;

const int INF = 0x3F3F3F3F;

int dp[10001][101];

int f(int w, int h) {
	if (w < h) swap(w, h);
	if (w <= 0 || h <= 0) return 0;

	int& ret = dp[w][h];
	if (ret != -1) return ret;
	if (w % h == 0) return ret = w / h;
	if (3 * h <= w) return ret = 1 + f(w - h, h); // 가로가 세로의 3배 이상인 경우

	ret = INF;
	for (int k = 1; 2 * k <= w; ++k) ret = min(ret, f(k, h) + f(w - k, h));
	for (int k = 1; 2 * k <= h; ++k) ret = min(ret, f(w, k) + f(w, h - k));
	return ret;
}

int main() {
	int w, h;
	scanf("%d %d", &w, &h);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(w, h));
	return 0;
}