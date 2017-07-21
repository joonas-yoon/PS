#include <cstdio>

typedef long long lld;

int main() {
	lld h, w, k;
	scanf("%lld %lld %lld", &h, &w, &k);
	lld H = h / k + (h % k != 0);
	lld W = w / k + (w % k != 0);
	printf("%lld", H * W);
	return 0;
}