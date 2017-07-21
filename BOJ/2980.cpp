#include <cstdio>

int main() {
	int n, L;
	scanf("%d %d", &n, &L);
	int sec = 0, d = 0, prev = 0;
	for (int r, g, i = 0; i < n; ++i) {
		scanf("%d %d %d", &d, &r, &g);
		if (d > L) break;
		sec += d - prev;
		if (sec % (r + g) < r) {
			sec += r - sec % (r + g);
		}
		prev = d;
	}
	sec += L - prev;
	printf("%d", sec);
	return 0;
}