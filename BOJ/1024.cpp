#include <cstdio>

typedef long long lld;

int main() {
	lld n, k;
	scanf("%lld %lld", &n, &k);
	for (int len = k; len <= 100; ++len) {
		int x = n / len;
		lld sum = x;
		for (int i = 0; i < (len - 1) / 2; ++i) sum += 2 * x;
		if (len % 2 == 0) sum += x + len / 2;
		if (sum == n) {
			int start = x - (len - 1) / 2;
            if (start < 0) continue;
			for (int i = start, j = 0; j < len; ++j, ++i) printf("%d ", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}