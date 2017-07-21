#include <cstdio>

int len;

int solve(int cur, int bit) {
	if (cur >= len) return bit == 0;

	int ret = 0;
	for (int i = 0; i < 10; ++i) {
		ret += solve(cur + 1, bit & ~(1 << i));
	}
	return ret;
}

int main() {
	int m;
	scanf("%d %d", &len, &m);
	int bit = 0;
	for (int x, i = 0; i < m; ++i) {
		scanf("%d", &x);
		bit |= 1 << x;
	}
	printf("%d\n", solve(0, bit));
	return 0;
}