#include <cstdio>
#include <algorithm>

const int INF = 0x3F3F3F3F;

int n;
int L[21], H[21];

int solve(int cur, int hp) {
	if (hp <= 0) return -INF;
	if (cur >= n) return 0;
	return std::max(
		H[cur] + solve(cur+1, hp-L[cur]),
		solve(cur+1, hp)
	);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &L[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &H[i]);
	printf("%d\n", solve(0, 100));
	return 0;
}