#include <cstdio>
int main() {
	long long n, i;
	scanf("%lld", &n);
	// 제곱수의 개수
	for (i = 1; i*i <= n; ++i);
	printf("%lld", i-1);
	return 0;
}