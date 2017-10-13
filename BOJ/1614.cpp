#include <cstdio>

using lld = long long;

int main() {
	int g[6] = { 0,1,2,2,2,1 };
	int n, k;
	scanf("%d %d", &n, &k);

	lld sum = (k / g[n]) * 8LL;
	k %= g[n];
	int a[8] = { 1,2,3,4,5,4,3,2 };
	for (int i = 0, c = 0; i < 8; ++i) {
		if (a[i] == n) {
			if (c++ == k) {
				sum += i;
				break;
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}