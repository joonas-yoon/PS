#include <cstdio>

int main() {
	int s, t, d;
	scanf("%d%d%d", &s, &t, &d);
	printf("%lld", (long long)d * t / s / 2LL);
	return 0;
}