#include <cstdio>

typedef long long lld;

int main() {
	lld l, r, x, y, k;
	scanf("%lld %lld %lld %lld %lld", &l, &r, &x, &y, &k);
	for (int i = x; i <= y; ++i) {
		if (l <= k*i && k*i <= r) return puts("YES"), 0;
	}
	puts("NO");
	return 0;
}