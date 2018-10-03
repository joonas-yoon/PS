#include <cstdio>

int main() {
	long long n;
	scanf("%lld", &n);
	int cnt = 0;
	for (long long i = 1; i*i <= n; ++i) {
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}