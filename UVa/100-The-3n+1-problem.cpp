#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long lld;

int main() {
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		int m = 1, l = a, r = b;
		if (a > b) swap(a, b);
		for (int i = a; i <= b; ++i) {
			int len = 1;
			lld n = i;
			while (n > 1) {
				if (n % 2) n = 3 * n + 1;
				else n >>= 1;
				len++;
			}
			m = max(m, len);
		}
		printf("%d %d %d\n", l, r, m);
	}
	return 0;
}