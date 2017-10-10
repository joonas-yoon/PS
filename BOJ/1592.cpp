#include <cstdio>

int main() {
	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);
	int cnt[1001] = {}, cur = 0, k = 0;
	for (; k >= 0; ++k) {
		if ((cnt[cur] += 1) >= m) break;
		if (cnt[cur] & 1)
			cur = (cur + l) % n;
		else
			cur = (cur + n - l) % n;
	}
	printf("%d\n", k);
	return 0;
}